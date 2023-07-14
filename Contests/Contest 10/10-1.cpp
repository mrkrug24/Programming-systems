#include <map>
#include <string>
#include <iostream>
using namespace std;

template <class T>
T Reverse (const T& a) {
    T reverse;
    for (auto i : a) {
        reverse.push_back(i);
    }
    
    return reverse;
}

void eq_Gr(map<char, int> &db_r, multimap<char, string> &db, const char left) {
    db_r[left] = 1;
    for (auto i : db) {if (i.first == left) {for (auto j : i.second) {if (!db_r[j] && isupper(j)) {eq_Gr(db_r, db, j);}}}}
}

int main() {
    char left; string right;
    map<char, int> db_r; multimap<char, string> db; 
    while (cin >> left >> right) {db_r[left] = 0; db.insert(pair<char, string>{left, right});}
    eq_Gr(db_r, db, 'S');
    for (auto i : db) {if (db_r[i.first] == 1) {cout << i.first << " " << i.second << endl;}}
    return 0;
}