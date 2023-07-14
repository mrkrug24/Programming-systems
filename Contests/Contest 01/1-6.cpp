#include <iomanip>
#include <iostream>
using namespace std;

class Point {
public:
    double x = 0.0, y = 0.0;
    Point(double a, double b) {x = a, y = b;}
};

class Line {
public:
    int flag = 0;
    double k = 0.0, b = 0.0, x = 0.0;
    Line (Point n, Point m) {(n.x - m.x == 0) ? (x = n.x, flag = 1) : (k = (n.y - m.y) / (n.x - m.x)), b = n.y - k * n.x;}

    friend int parallel(Line l_1, Line l_2) {
        if (l_1.flag == 0 && l_2.flag == 0) {
            if (l_1.k == l_2.k && l_1.b == l_2.b) {
                return 2;
            } else if (l_1.k == l_2.k) {
                return 0;
            }
        }

        if (l_1.flag == 1 && l_2.flag == 1) {
            if (l_1.x == l_2.x) {
                return 2;
            } else {
                return 0;
            }
        }

        return 1;
    }

    friend void intersection(Line l_1, Line l_2, double &x, double &y) {
        if (l_1.flag == 0 && l_2.flag == 0) {
            x = (l_1.b - l_2.b) / (l_2.k - l_1.k);
            y = l_1.k * x + l_1.b;

        } else if (l_1.flag == 1) {
            x = l_1.x;
            y = l_2.k * x + l_2.b;

        } else if (l_2.flag == 1) {
            x = l_2.x;
            y = l_1.k * x + l_1.b;
        }
    }
};

int
main(int argc, char *argv[])
{
    double x_1, y_1, x_2, y_2, x_3, y_3, x_4, y_4;
    cin >> x_1 >> y_1 >> x_2 >> y_2 >> x_3 >> y_3 >> x_4 >> y_4;

    Point a_1(x_1, y_1);
    Point b_1(x_2, y_2);
    Point a_2(x_3, y_3);
    Point b_2(x_4, y_4);

    Line l_1(a_1, b_1);
    Line l_2(a_2, b_2);

    int par = parallel(l_1, l_2);
    cout << par;

    if (par != 1) {
        cout << endl;
    } else {
        double x, y;
        intersection(l_1, l_2, x, y);
        cout << fixed << setprecision(5) << ' ' << x << ' ' << y << endl;
    }

    return 0;
}