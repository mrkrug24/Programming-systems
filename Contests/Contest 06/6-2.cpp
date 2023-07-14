#include <set>
#include <map>
#include <list>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <iostream>
using namespace std;

template<typename Cont, typename Pred> 
Cont myfilter(const Cont &c, Pred p) {
    Cont new_c; 
    for (const auto &el : c) {if (p(el)) {new_c.insert(new_c.end(), el);}}
    return new_c;
}