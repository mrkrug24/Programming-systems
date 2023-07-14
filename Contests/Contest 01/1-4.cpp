#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;

int
main(int argc, char *argv[])
{
    long long cnt = 0;
    long double sum_1 = 0, sum_2 = 0, cur;
    cin >> cur;
    
    while (!cin.eof()) {
        sum_1 += cur;
        sum_2 += cur * cur;
        cnt++;
        cin >> cur;
    }

    double average = sum_1 / cnt;
    double deviation = sqrt(sum_2 / cnt - average * average);
    cout << fixed << setprecision(10) << average << endl << deviation << endl;

    return 0;
}