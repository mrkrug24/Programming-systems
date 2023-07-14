#include <set>
#include <map>
#include <list>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <iostream>
using namespace std;

template<typename Cont> 
typename Cont::value_type process(const Cont &c) {
    if (c.empty()) {return typename Cont::value_type();} 
    int cnt = 1;
    typename Cont::const_iterator it = c.end();
    typename Cont::value_type sum = *(--it); it--;

    for (; it != c.begin() && cnt < 5; cnt++, it--) {if (cnt % 2 == 0) {sum += *it;}}
    if (cnt == 4 || cnt == 2 || cnt == 0) {sum += *it;}

    return sum;
}