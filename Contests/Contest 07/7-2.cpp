#include <cmath>
#include <sstream>
#include <iostream>
using namespace std;

class Figure {
public:
    virtual double get_square() const = 0;
    virtual ~Figure() {};
};

class Rectangle: public Figure {
    double width;
    double height;
public:
    Rectangle(double w = 0, double h = 0) {width = w; height = h;}
    virtual double get_square() const override {return width * height;}
    static Rectangle *make(const string &init_str) {
        double w, h;
        stringstream ss(init_str); ss >> w >> h;
        return new Rectangle(w, h);
    }
};

class Square: public Figure {
    double length;
public:
    Square(double l = 0) {length = l;}
    virtual double get_square() const override {return length * length;}
    static Square *make(const string &init_str) {
        double l;
        stringstream ss(init_str); ss >> l;
        return new Square(l);
    }
};

class Circle: public Figure {
    double radius;
public:
    Circle(double r = 0) {radius = r;}
    virtual double get_square() const override {return M_PI * radius * radius;}
    static Circle *make(const string &init_str) {
        double r;
        stringstream ss(init_str); ss >> r;
        return new Circle(r);
    }
};