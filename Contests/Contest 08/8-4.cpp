#include <cmath>
#include <array>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <complex>
#include <iostream>
using namespace std;

namespace Equations {
template <typename T>
    pair<bool, vector<T>> quadratic(const array<T, 3> &v) {
        pair<bool, vector<T>> ans;
        T a = v[2], b = v[1], c = v[0], z = T(0), t = T(2), f = T(4);

        if (a == z && b == z && c == z) {ans.first = false;}
        else {ans.first = true;}

        if (a == z && b != z) {ans.second = {-c / b};}
        else if (a != z) {ans.second = {(-b-sqrt(b*b-f*a*c))/(t*a), (-b+sqrt(b*b-f*a*c))/(t*a)};}

        return ans;
    }
};