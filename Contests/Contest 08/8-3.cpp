#include <cstdio>
#include <iomanip>
#include <utility>
#include <iostream>
using namespace std;

class E {};

class S {
    int sum, num = 0, brk = 0;
public:
    explicit operator bool() const {return brk == 0;}

    S (int cur = 1) {
        num = cur;
        if (!(cin >> sum)) {(num == 0) ? (throw E()) : (brk = 1);}
    }

    S(const S &cur) {
        sum = cur.sum;
        try {S s(0); sum += s.sum;}
        catch (E &x) {brk = 1;}
    }

    ~S() {if (num == 0 && brk != 0 ) cout << sum << endl;}
};