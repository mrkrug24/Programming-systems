#include <cstdio>
#include <iomanip>
#include <iostream>
using namespace std;

class Figure {
public:
    virtual double get_square() const = 0;
    virtual ~Figure() {};
};