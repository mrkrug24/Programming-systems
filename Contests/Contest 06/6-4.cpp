#include <vector>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

template <typename Iter_indx, typename Iter_data>
Iter_data myremove(Iter_indx first, Iter_indx last, Iter_data begin, Iter_data end) {
    int i = 0; Iter_data res = begin;
    for (auto it = begin; it != end; ++it, ++i) {if (find(first, last, i) == last) {iter_swap(res++, it);}}
    return res;
}