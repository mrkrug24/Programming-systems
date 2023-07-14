#include <map>
#include <vector>
#include <iostream>
using namespace std;
typedef pair<uint64_t, uint64_t> place;

int main(int argc, char **argv) {
    map<place, uint64_t> matrix;
    uint64_t r, c, v, mod = 4294967161;
    vector<uint64_t> sep = {0, 0, mod};
    
    while (cin >> r >> c >> v) {
        if (vector<uint64_t>{r, c, v} != sep) {
            place coord = {r, c};
            v %= mod;
            if (matrix.find(coord) != matrix.end()) {
                matrix[coord] += v;
                matrix[coord] %= mod;
            } else {
                matrix.insert(pair<place, uint64_t>(coord, v));
            }
        }
    }

    for (auto i : matrix) {
        if (i.second % mod != 0) {
            cout << i.first.first << " " << i.first.second << " " << i.second << endl;
        }
    }

    return 0;
}