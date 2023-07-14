#include <cstdio>
#include <iomanip>
#include <iostream>
using namespace std;

class Convolution {
    string s;
public:
    Convolution(const string &str)  {s = str;}
    ~Convolution() {cout << s << endl;}
};

void print_rev() {
    string str;
    try {if (cin >> str) {print_rev(); Convolution cur(str);}}
    catch (...) {}
}

int main() {
    print_rev();
    return 0;
}