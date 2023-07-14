#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
using namespace std;

void process(const vector<uint64_t>& input, vector<uint64_t>& output, int step) {
    auto outIter = output.rbegin();
    int len = input.size();
    int cur = 0;

    for (auto inIter = input.begin(); inIter != input.end(); inIter += step, cur += step) {
        if (outIter == output.rend()) {
            break;
        }

        *outIter += *inIter;
        ++outIter;

        if (cur + step >= len) {
            break;
        }
    }
}