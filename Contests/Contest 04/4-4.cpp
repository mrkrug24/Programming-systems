#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

class MeanCalculator {
private:
    int cnt;
    double sum;
public:
    MeanCalculator() {cnt = 0; sum = 0.0;}
    void operator()(double x) {sum += x; ++cnt;}
    double calculate_mean() const {return sum / cnt;}
};

int main() {
    double x;
    vector<double> numbers;
    while (cin >> x) {numbers.push_back(x);} 

    int border_size = numbers.size() * 0.1;
    numbers.erase(numbers.begin(), numbers.begin() + border_size);
    numbers.erase(numbers.end() - border_size, numbers.end());
    sort(numbers.begin(), numbers.end());

    int inner_size = numbers.size() * 0.1;
    numbers.erase(numbers.begin(), numbers.begin() + inner_size);
    numbers.erase(numbers.end() - inner_size, numbers.end());

    MeanCalculator mean_calculator = for_each(numbers.begin(), numbers.end(), MeanCalculator());
    cout << fixed << setprecision(10) << mean_calculator.calculate_mean() << endl;

    return 0;
}