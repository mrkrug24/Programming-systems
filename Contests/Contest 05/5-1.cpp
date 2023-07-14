#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(uint32_t a, uint32_t b) {
    uint32_t cnt_a = 0, cnt_b = 0;
    uint32_t m = max(a, b);

    while (m > 0) {
        if (a > 0) {cnt_a += 1 & a; a >>= 1;}
        if (b > 0) {cnt_b += 1 & b; b >>= 1;}
        m = max(a, b);
    }

    return (cnt_a < cnt_b);
}

int main(int argc, char **argv) {
    uint32_t cur;
    vector<uint32_t> sequence;
    
    while (cin >> cur) {sequence.push_back(cur);}
    stable_sort(sequence.begin(), sequence.end(), cmp);
    for (auto i : sequence) {cout << i << endl;}

    return 0;
}