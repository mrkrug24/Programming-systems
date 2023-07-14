#include <iostream>

using namespace std;

int main() {
    char c;
    int k = 0, m = 0;
    bool zeroGroup = true;
    bool valid = true;

    while(cin >> c) {
        if(c == '0') {
            if(zeroGroup) {
                k++;
            } else {
                valid = false;
                break;
            }
        } else if(c == '1') {
            if(zeroGroup) {
                zeroGroup = false;
                m++;
            } else {
                m++;
            }
        } else {
            valid = false;
            break;
        }
    }

    if(valid && k > 0 && m > 0) {
        while(cin >> c) {
            if(c == '0') {
                if(zeroGroup) {
                    k++;
                } else {
                    if(k > 0 && m > 0) {
                        zeroGroup = true;
                        k = 1;
                        m = 0;
                    } else {
                        valid = false;
                        break;
                    }
                }
            } else if(c == '1') {
                if(zeroGroup) {
                    valid = false;
                    break;
                } else {
                    m++;
                }
            } else {
                valid = false;
                break;
            }
        }
    } else {
        valid = false;
    }

    if(valid && k > 0 && m > 0) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}