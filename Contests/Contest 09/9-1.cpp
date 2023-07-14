#include <cstdio>
#include <iomanip>
#include <iostream>
using namespace std;

int language(string &str) {
    auto i = str.begin();
    while (*i == '3' || *i == '4') {i++;}
    while (*i == '1' || *i == '2') {i++;}
    if (i == str.end()) {return 1;}
    return 0;
}

int main() {
    string str;
    while (cin >> str) {cout << language(str) << endl;}
    return 0;
}