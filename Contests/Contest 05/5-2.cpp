#include <map>
#include <string>
#include <iostream>
using namespace std;
typedef pair<uint64_t, uint64_t> block;

int main(int argc, char **argv) {
    string name;
    uint64_t mark;
    map<string, block> db;
    
    while (cin >> name >> mark) {
        if (db.find(name) != db.end()) {
            db[name].first++;
            db[name].second += mark;
        } else {
            db.insert(pair<string, block>(name, block(1, mark)));
        }
    }

    for (auto i : db) {cout << i.first << " " << (long double)i.second.second / i.second.first << endl;}
    
    return 0;
}