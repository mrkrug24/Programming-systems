#include <iomanip>
#include <iostream>
using namespace std;

class C {
public:
    C (const C &link) {;}
    C (int x = 0, int y = 0) {;}
   
    C &operator++() {return *this;}
    C operator[] (int x) {return *this;}

    friend C operator&(const C &x) {return 0;}
    friend int operator~(const C &x) {return 0;}
    friend int operator+(const C &x, const C &y) {return 0;}
    friend int operator*(const C &x, const C y[]) {return 0;}
};