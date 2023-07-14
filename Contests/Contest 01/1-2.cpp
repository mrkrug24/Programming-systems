#include <iomanip>
#include <iostream>
using namespace std;

class A {
public:
    int num, flag = 0;
    A () {flag = 1; cin >> num;}
    A (const A &a) {cin >> num; num += a.num;}
    ~A () {if (flag == 0) {cout << num;}}
};