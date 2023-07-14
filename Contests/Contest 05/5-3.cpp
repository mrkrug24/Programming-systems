#include <map>
#include <set>
#include <iomanip>
#include <iostream>
using namespace std;

class Date {
public:
    string date_op;
    Date(string &str) {
        stringstream stream;
        stream << str.substr(0, str.find("/"));
        str.erase(str.begin(), str.begin() + str.find("/") + 1);
        stream << "/" << setfill('0') << setw(2) << str.substr(0, str.find("/"));
        str.erase(str.begin(), str.begin() + str.find("/") + 1);
        stream << "/" << setfill('0') << setw(2) << str;
        date_op = stream.str();
    }
};

int main(int argc, char **argv) {
    int mark;
    string name, date;
    set<string> dates;
    map<string, map<string, int>> db;
    
    while (cin >> name >> date >> mark) {
        string date_op = Date(date).date_op;
        dates.insert(date_op);
        if (db.find(name) == db.end()) {db[name] = map<string,int>{{date_op, mark}};}
        else {db[name][date_op] = mark;}
    }

    cout << ". "; for (auto i : dates) {cout << i << " ";} cout << endl;

    for (auto i : db) {
        cout << i.first << " ";
        for (auto j : dates) {(i.second.find(j) != i.second.end()) ? (cout << i.second[j] << " ") : (cout << ". ");}
        cout << endl;
    }

    return 0;
}