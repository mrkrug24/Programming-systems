#include <cmath>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
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

class Factory {
public:
    static Factory &factory_instance() {static Factory inst; return inst;}
    static Figure *get_figure(string info) {
        string type, params;
        stringstream ss(info);
        ss >> type; getline(ss, params);
        if (type == "R") {return Rectangle::make(params);}
        else if (type == "S") {return Square::make(params);}
        else if (type == "C") {return Circle::make(params);}
        else {return nullptr;}
    }
};

bool cmp(const Figure *a, const Figure *b) {return (a->get_square() < b->get_square());}

int main(int argc, char **argv) {
    string info;
    Factory handler;
    vector<Figure*> db;
    
    while (getline(cin, info)) {db.push_back(handler.factory_instance().get_figure(info));}
    stable_sort(db.begin(), db.end(), cmp);
    for (auto i : db) {cout << i->to_string() << endl; delete(i);}

    return 0;
}