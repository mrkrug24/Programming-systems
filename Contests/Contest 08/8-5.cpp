#include <chrono>
#include <iomanip>
#include <iostream>
using namespace std;
using namespace chrono;

int diff_date(const string &date_1_str, const string &date_2_str) {
    tm date_1 = {}, date_2 = {};
    istringstream date_1_stream(date_1_str), date_2_stream(date_2_str);
    date_1_stream >> get_time(&date_1, "%Y-%m-%d");
    date_2_stream >> get_time(&date_2, "%Y-%m-%d");
    auto time_1 = system_clock::from_time_t(mktime(&date_1));
    auto time_2 = system_clock::from_time_t(mktime(&date_2));
    duration<double> diff = time_1 - time_2;
    return abs(diff.count() / (60 * 60 * 24));
}

int main() {
    int ans = 0;
    string prev, cur;
    cin >> prev;

    while (cin >> cur) {ans += diff_date(prev, cur); prev = cur;}
    cout << ans << endl;

    return 0;
}