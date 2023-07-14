#include <set>
#include <map>
#include <list>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <functional>
using namespace std;

template<typename Iter, typename Func>
void myapply(Iter begin, Iter end, Func f) {
    for (auto it = begin; it != end; ++it) {f(*it);}
}

template<typename Iter>vector<reference_wrapper<typename iterator_traits<Iter>::value_type>>
myfilter2(Iter begin, Iter end, function<bool(typename iterator_traits<Iter>::value_type&)> p) {
    vector<reference_wrapper<typename iterator_traits<Iter>::value_type>> result;
    for (auto it = begin; it != end; ++it) {if (p(*it)) {result.push_back(*it);}}
    return result;
}