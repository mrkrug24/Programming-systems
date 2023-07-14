#include <map>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <functional>

using std::map;
using std::vector;
using std::function;
using std::end;
using std::copy;
using std::begin;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::ostringstream;
using std::setprecision;

namespace numbers 
{
    class complex 
    {
    public:
        double re_part, im_part;
        complex(double x = 0.0, double y = 0.0) {re_part = x; im_part = y;}
        double re() const {return re_part;}
        double im() const {return im_part;}
        double abs() const {return sqrt(re_part * re_part + im_part * im_part);}
        double abs2() const {return re_part * re_part + im_part * im_part;}
        complex operator~() const {return complex(re_part, -im_part);}
        complex operator-() const {return complex(-re_part, -im_part);}
        complex operator+= (const complex &z) {re_part += z.re_part; im_part += z.im_part; return *this;}
        complex operator-= (const complex &z) {re_part -= z.re_part; im_part -= z.im_part; return *this;}

        complex operator*= (const complex &z) {
            double re_cpy = re_part;
            double im_cpy = im_part;
            re_part = z.re() * re_cpy - z.im() * im_cpy;
            im_part = z.re() * im_cpy + z.im() * re_cpy;
            return *this;
        }

        complex operator/= (const complex &z) {
            double re_cpy = re_part;
            double im_cpy = im_part;
            re_part = (z.re() * re_cpy + z.im() * im_cpy) / z.abs2();
            im_part = (z.re() * im_cpy - z.im() * re_cpy) / z.abs2();
            return *this;
        }

        friend complex operator+ (const complex &x, const complex &y) {complex sum = x; return (sum += y);}
        friend complex operator- (const complex &x, const complex &y) {complex sub = x; return (sub -= y);}
        friend complex operator* (const complex &x, const complex &y) {complex mul = x; return (mul *= y);}
        friend complex operator/ (const complex &x, const complex &y) {complex div = x; return (div /= y);}

        explicit complex(const string z) {
            string str = z;
            str.erase(str.begin());
            str.erase(str.end() - 1);
            re_part = stod(str.substr(0, str.find(",")));
            im_part = stod(str.substr(str.find(",") + 1));
        }

        string to_string() const {
            stringstream str;
            str << setprecision(10) << "(" << re_part << "," << im_part << ")";
            return str.str();
        }
    };
};

namespace numbers {
    class complex_stack {
    private:
        size_t cnt;
        size_t ssize;
        complex *arr;
    public:
        size_t size() const {return ssize;}
        complex &operator[](size_t i) {return arr[i];}
        complex &operator[](size_t i) const {return arr[i];}
        complex operator+() const {return arr[ssize - 1];}
        complex_stack() {cnt = 0; ssize = 0; arr = nullptr;}
        friend complex_stack operator<<(const complex_stack obj, const complex num);
        complex_stack(complex_stack &&tmp) {cnt = tmp.cnt; ssize = tmp.ssize; arr = tmp.arr; tmp.arr = nullptr;}

        complex_stack(size_t a, size_t b = 0) {cnt = a; ssize = b;
            arr = static_cast<complex*>(::operator new(sizeof(complex) * cnt));
        }

        complex_stack(const complex_stack &tmp) {cnt = tmp.cnt; ssize = tmp.ssize;
            arr = static_cast<complex*>(::operator new(sizeof(complex) * cnt));
            for (size_t i = 0; i < ssize; i++) {new(arr + i)complex(tmp.arr[i]);}
        }

        ~complex_stack() {
            for (size_t i = 0; (cnt > 0) && (i < ssize); i++) {arr[i].~complex();}
            ::operator delete(arr);
            cnt = 0;
            ssize = 0;
        }

        complex_stack operator~() const {
            complex_stack obj_2(cnt, ssize - 1);
            for (size_t i = 0; i < ssize - 1; i++) {new(obj_2.arr + i)complex(arr[i]);}
            return obj_2;
        }

        complex_stack &operator=(complex_stack &&obj) {
            if (&obj != this) {
                for (size_t i = 0; i < ssize; i++) {arr[i].~complex();}
                ::operator delete(arr);
                arr = obj.arr;
                obj.arr = nullptr;
                cnt = obj.cnt;
                ssize = obj.ssize;
            }
            return *this;
        }

        complex_stack& operator=(const complex_stack &obj) {
            if (&obj != this) {
                cnt = obj.cnt;
                ssize = obj.ssize;
                for (size_t i = 0; i < ssize; i++) {arr[i].~complex();}
                ::operator delete(arr);
                arr = static_cast<complex*>(::operator new(sizeof(complex) * cnt));
                for (size_t i = 0; i < ssize; i++) {new(arr + i)complex(obj.arr[i]);}
            }
            return *this;
        }
    };

    complex_stack operator<<(const complex_stack obj, const complex num) {
        size_t cnt_2;
        if (obj.cnt == 0) {cnt_2 = 1;}
        (obj.cnt == obj.ssize) ? (cnt_2 = 2 * obj.cnt) : (cnt_2 = obj.cnt);
        if (obj.cnt == 0) {cnt_2 = 1;}

        complex_stack obj_2(cnt_2, obj.ssize + 1);
        for (size_t i = 0; i < obj.ssize; i++) {new(obj_2.arr + i)complex(obj[i]);}
        new (obj_2.arr + obj.ssize)complex(num);

        return obj_2;
    }
};

namespace numbers {
    complex_stack move(complex_stack &stack, string op, const complex &z) {
        if (op == "+" || op == "-" || op == "*" || op == "/") {
            complex num_1 = +stack;
            stack = ~stack;
            complex num_2 = +stack;
            stack = ~stack;
            if (op == "+") {num_2 += num_1;} 
            else if (op == "-") {num_2 -= num_1;} 
            else if (op == "*") {num_2 *= num_1;} 
            else if (op == "/") {num_2 /= num_1;}
            stack = stack << num_2;

        } else if (op == "~" || op == "#") {
            complex tmp = +stack;
            stack = ~stack;
            if (op == "~") {tmp = ~tmp;} 
            else if (op == "#") {tmp = -tmp;}
            stack = stack << tmp;

        } else if (op == "!") {
            complex tmp = +stack;
            stack = stack << tmp;

        } else if (op == ";") {
            stack = ~stack;

        } else if (op == "z") {
            stack = stack << z;

        } else {
            complex tmp(op);
            stack = stack << tmp;
        }

         return stack;
    }

    complex eval(const std::vector<std::string> &args, const complex &z) {
        complex num;
        complex_stack stack;
        size_t ssize = args.size();
        map<string, function<complex_stack(complex_stack &stack, string op, const complex &z)>>act;
        act["z"] = [](complex_stack &stack, string op, const complex &z) -> complex_stack {return move(stack, op, z);};
        act["+"] = [](complex_stack &stack, string op, const complex &z) -> complex_stack {return move(stack, op, z);};
        act["-"] = [](complex_stack &stack, string op, const complex &z) -> complex_stack {return move(stack, op, z);};
        act["*"] = [](complex_stack &stack, string op, const complex &z) -> complex_stack {return move(stack, op, z);};
        act["/"] = [](complex_stack &stack, string op, const complex &z) -> complex_stack {return move(stack, op, z);};
        act["!"] = [](complex_stack &stack, string op, const complex &z) -> complex_stack {return move(stack, op, z);};
        act[";"] = [](complex_stack &stack, string op, const complex &z) -> complex_stack {return move(stack, op, z);};
        act["~"] = [](complex_stack &stack, string op, const complex &z) -> complex_stack {return move(stack, op, z);};
        act["#"] = [](complex_stack &stack, string op, const complex &z) -> complex_stack {return move(stack, op, z);};

        if (ssize > 0) {
            for (size_t i = 0; i < ssize; i++) {
                (act.find(args[i])!=act.end())?(stack=act[args[i]](stack,args[i],z)):(stack=move(stack,args[i],z));
            }
            num = +stack;
        }
        
        return num;
    }
};