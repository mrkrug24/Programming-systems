#include <iomanip>
#include <iostream>
using namespace std;

int
main(int argc, char **argv)
{
    char cur;
    int is_number = 0;
    int zeroes_seq = 0;
    cin >> noskipws;
    cin.tie(nullptr);
    
    while ((cin >> cur) && (cur != EOF)) {
        if (cur == '0') {
            zeroes_seq = 1;
            if (is_number == 1) {
                cout << '0';
            }

        } else if ('1' <= cur && cur <= '9') {
            zeroes_seq = 0;
            is_number = 1;
            cout << cur;
        
        } else {
            if (zeroes_seq == 1 && is_number == 0) {
                cout << '0';
            }
            zeroes_seq = 0;
            is_number = 0;
            cout << cur;
        }
    }

    if (zeroes_seq == 1 && is_number == 0) {
        cout << '0';
    }

    return 0;
}