#include <cstdio>
#include <iomanip>
#include <iostream>
using namespace std;

class Result {
    int64_t val, brk;
public:
    Result(int64_t v, int64_t b = 0) {val = v; brk = b;}
    int64_t get_value() const {return val;}
    int64_t check_break() const {return brk;}
};

void func(int64_t a, int64_t b, uint64_t k) {
    if (k == 0) {throw Result(a + b);}
    if (k > 0 && b == 1) {throw Result(a);}
    if (k > 0 && b > 1) {try{func(a, b - 1, k);} catch(Result &r) {func(a, r.get_value(), k - 1);}}
    throw Result(0, 1);
}

int main() {
    int64_t a, b; uint64_t k;
    while (cin >> a >> b >> k) {
        try {func(a, b, k);}
        catch (Result &cur) {if (cur.check_break() == 0) {cout << cur.get_value() << endl;}}
    }
    return 0;
}