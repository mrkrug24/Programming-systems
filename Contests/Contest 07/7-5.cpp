#include <cstdio>
#include <iomanip>
#include <iostream>
using namespace std;

class Figure {
public:
    virtual bool equals(const Figure *fgr) const = 0;
    virtual ~Figure() {} 
};

class Rectangle: public Figure {
    int a, b;
public:
    Rectangle(int da = 0, int db = 0) {a = da; b = db;}
    virtual bool equals(const Figure *fgr) const override {
        bool ans; const auto p = dynamic_cast<const Rectangle*>(fgr);
        (p && (p->a == a) && (p->b == b)) ? (ans = true) : (ans = false);
        return ans;
    }
};

class Triangle: public Figure {
    int a, b, c;
public:
    Triangle(int da = 0, int db = 0, int dc = 0) {a = da; b = db; c = dc;}
    bool equals(const Figure *fgr) const override {
        bool ans; const auto p = dynamic_cast<const Triangle*>(fgr);
        (p && (p->a == a) && (p->b == b) && (p->c == c)) ? (ans = true) : (ans = false);
        return ans;
    }
};