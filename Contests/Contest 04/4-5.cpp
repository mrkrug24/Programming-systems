#include <list>
#include <iostream>
using namespace std;

int main() {
    list<int> lst;
    int n, cmd, val;
    while (cin >> n && n != 0) {lst.push_back(n);}

    while (cin >> cmd) {
        auto it = lst.begin();
        size_t cmp = abs(cmd) - 1;

        if ((cmd < 0) && (cmp < lst.size())) {advance(it, cmp); lst.erase(it);}
        
        if (cmd > 0 && cin >> val) {
            if (cmp >= lst.size()) {lst.push_back(val);} else {advance(it, cmp); lst.insert(it, val);}
        }
    }

    for (auto i : lst) {cout << i << endl;}
    lst.clear();

    return 0;
}