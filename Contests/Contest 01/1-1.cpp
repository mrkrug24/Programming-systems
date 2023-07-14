#include <iomanip>
#include <iostream>
using namespace std;

class Sum {
    int a, b;
public:
    Sum (long long x, long long y) {a=x, b=y;}
    Sum (const Sum &x, long long y) {a=x.a + x.b, b=y;}

    long long get() const {
        return a + b;
    }
};