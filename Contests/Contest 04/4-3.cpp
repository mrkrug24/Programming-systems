#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void process(const vector<int> &v1, vector<int> &v2) {
    vector<int> v1_copy(v1);
    sort(v1_copy.begin(), v1_copy.end());
    auto last = unique(v1_copy.begin(), v1_copy.end());
    v1_copy.erase(last, v1_copy.end());

    for (auto it = v1_copy.rbegin(); it != v1_copy.rend(); ++it) {
        int idx = *it;

        if (idx >= 0 && idx < static_cast<int>(v2.size())) {
            v2.erase(v2.begin() + idx);
        }
    }
}