#include <map>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <functional>
#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_complex_eval.h"

using std::stod;
using std::stoi;
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
using numbers::complex;
using numbers::complex_stack;

int main (int argc, char **argv) {
    int n = stoi(argv[3]);
    vector<string> pol_not;
    double r = stod(argv[2]), step = 2 * M_PI / n, val;
    complex c(argv[1]), width(step, 0.0), ans;
    for (int i = 4; i < argc; i++) {pol_not.push_back(argv[i]);}
    
    for (int i = 0; i < n; ++i) {
        val = step * (0.5 + i);
        complex z(c.re() + r * cos(val), c.im() + r * sin(val));
        complex d((-1) * r * sin(val), r * cos(val));
        ans += eval(pol_not, z) * width * d;
    }
   
    cout << ans.to_string() << endl;
    return 0;
}