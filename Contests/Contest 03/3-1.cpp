#include <cmath>
#include <cstdio>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
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