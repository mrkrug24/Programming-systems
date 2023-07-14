#include <iostream>
using namespace std;

void print_str(size_t n, size_t k){
    if (n == 0) {return;}
    size_t m = (k - 2 * n) / 2;
    string cur = string(n, 'a') + string(m, 'b') + string(m, 'c') + string(n, 'd');
    cout << cur << endl;
    print_str(n - 1, k);
}

int main(){
    size_t k; cin >> k;
    if (k % 2 == 0) {print_str((k - 2) / 2, k);}
    return 0;
}