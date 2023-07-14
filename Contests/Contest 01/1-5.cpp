#include <iomanip>
#include <iostream>
using namespace std;

int 
main(int argc, char **argv) 
{
    int new_str = 1, len = 0;
    uint32_t number, offset, bytes[4];
    
    while (((new_str == 0) || (cin >> hex >> offset)) &&
            ((cin >> hex >>bytes[0]) && (cin >> hex >> bytes[1]) && 
            (cin >> hex >> bytes[2]) && (cin >> hex >> bytes[3]))) {
        
        len += 4;
        number = 0;
        (len % 16 == 0) ? (len = 0, new_str = 1) : (new_str = 0);
        for (int i = 0; i < 4; i++) {number <<= 8; number |= bytes[i];}
        cout << number << endl;
    }
    
    return 0;
}