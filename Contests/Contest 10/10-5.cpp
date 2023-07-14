#include <stack>
#include <string>
#include <iostream>
using namespace std;

int is_op(char c){return (c == '+' || c == '-' || c == '*' || c == '/');}
int is_var(char c){return ('a' <= c && c <= 'z');}

string infix(string &expr) {
    stack<string> s;
    int len = expr.length();
    
    for(int i = 0; i < len; i++) {
        char c = expr[i];

        if (is_var(c) == 1) {s.push(string(1, c));}
        else if (is_op(c) == 1) {
            string op_1 = s.top(); s.pop();
            string op_2 = s.top(); s.pop();
            s.push("(" + op_2 + c + op_1 + ")");
        }
    }

    return s.top(); 
}

int main() {
    string expr; getline(cin, expr);
    cout << infix(expr) << endl;
    return 0;
}