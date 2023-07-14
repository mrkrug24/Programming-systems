#include <set>
#include <map>
#include <list>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <functional>
using namespace std;

template <typename Iter>
void selection_sort(Iter begin, Iter end) {
    for (Iter i = begin; i != end; ++i) {
        Iter min = i;
        for (Iter j = next(i); j != end; ++j) {if (*j < *min) {min = j;}}
        iter_swap(i, min);
    }
}

template <typename Iter, class Func>
void selection_sort(Iter begin, Iter end, Func cmp) {
    for (Iter i = begin; i != end; ++i) {
        Iter min = i;
        for (Iter j = next(i); j != end; ++j) {if (cmp(*j, *min)) {min = j;}}
        iter_swap(i, min);
    }
}