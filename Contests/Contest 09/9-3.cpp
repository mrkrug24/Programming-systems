#include <cstdio>
#include <iomanip>
#include <iostream>
using namespace std;

int language(string &str) {
    auto i = str.begin();
    int n = 0, m = 0, k = 0, l = 0;
    while (*i == 'a') {i++; n++;}
    while (*i == '0') {i++; m++;}
    while (*i == 'b') {i++; k++;}
    while (*i == '1') {i++; l++;}
    if (i == str.end() && n == k && m == l && k > 0 && m > 0) {return 1;}
    return 0;
}

int main() {
    string str;
    while (cin >> str) {cout << language(str) << endl;}
    return 0;
}