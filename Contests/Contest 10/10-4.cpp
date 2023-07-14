#include <iostream>
#include <string>

using namespace std;

string remove_extra_parentheses(string expr) {
    int n = expr.length();
    int paren_count = 0;
    int start_pos = -1;
    for (int i = 0; i < n; i++) {
        if (expr[i] == '(') {
            if (paren_count == 0) {
                start_pos = i;
            }
            paren_count++;
        } else if (expr[i] == ')') {
            paren_count--;
            if (paren_count == 0 && start_pos != -1 && i == n - 1) {
                return remove_extra_parentheses(expr.substr(start_pos + 1, i - start_pos - 1));
            }
        }
        if (paren_count == 0 && start_pos != -1) {
            string subexpr = expr.substr(start_pos + 1, i - start_pos - 1);
            string new_subexpr = remove_extra_parentheses(subexpr);
            if (subexpr != new_subexpr) {
                expr.replace(start_pos, i - start_pos + 1, new_subexpr);
                n = expr.length();
                i = start_pos + new_subexpr.length() - 1;
                start_pos = -1;
            } else {
                start_pos = -1;
            }
        }
    }
    return expr;
}

int main() {
    string expr;
    getline(cin, expr);
    cout << remove_extra_parentheses(expr) << endl;
    return 0;
}