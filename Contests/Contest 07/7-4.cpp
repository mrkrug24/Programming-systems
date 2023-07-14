#include <cmath>
#include <iostream>
using namespace std;

namespace Game {
    template<typename T>
    class Coord {
    public:
        using value_type = T; value_type row, col;
        Coord (T r = value_type(), T c = value_type()) : row(r), col(c) {}
    };

    template<typename T>
    typename T::value_type dist(const T &area, const T &a, const T &b) {
        typename T::value_type col_dif = a.col - b.col;
        typename T::value_type row_dif = a.row - b.row + a.col / 2 - b.col / 2;
        return (row_dif * col_dif < 0) ? (abs(row_dif) + abs(col_dif)) : (max(abs(row_dif), abs(col_dif)));
    } 
};