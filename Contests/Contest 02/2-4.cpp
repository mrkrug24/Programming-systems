#include <string>
#include <iostream>
using namespace std;

int
main(int argc, char **argv)
{
    int cnt = 0;
    char cur, prev = '\0';

    while (cin.get(cur) && !cin.eof()) {
        if (cur != prev) {
            if (cnt <= 4 && prev != '#') {
                cout << string(cnt, prev);
            } else {
                cout << '#' << prev << hex << cnt << '#';
            }

            prev = cur;
            cnt = 1;
        } else {
            ++cnt;
        }
    }

    if (cnt <= 4 && prev != '#') {
        cout << string(cnt, prev);
    } else {
        cout << '#' << prev << hex << cnt << '#';
    }

    return 0;
}