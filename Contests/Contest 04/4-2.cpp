#include <vector>
#include <iostream>
using namespace std;

void process(vector<int64_t>& vec, int64_t threshold) {
    int cur = 0;
    int len = vec.size();

    for (auto it = vec.rbegin(); cur <= 2 * len + 2; cur++) {
        len = vec.size();
        
        if (cur >= len) {
            break;
        }

        it = vec.rbegin();
        it += cur;

        if (*it >= threshold) { 
            cur += 1;
            vec.push_back(*it);
        }
    }
}