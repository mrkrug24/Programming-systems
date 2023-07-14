#include <array>
#include <iostream>
using namespace std;

class Matrix {
private:
    array<array<int, 3>, 3> m;
public:
    Matrix () {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                m[i][j] = 0;
            }
        }
    }
    
    int & operator[] (int i , int j) {
        return m[i][j];
    }
    
    array<int, 3> & operator[](int i) {
        return m[i];
    }
    
    auto begin() {return m.begin(); }
    auto end() {return m.end(); }
};

int main() {
    return 0;
}