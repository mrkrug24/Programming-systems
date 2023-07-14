#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    // считываем функцию перехода
    unordered_map<string, unordered_map<char, string>> transitions;
    string cur_state, symbol, new_state;
    while (cin >> cur_state && cur_state != "END") {
        cin >> symbol >> new_state;
        transitions[cur_state][symbol[0]] = new_state;
    }

    // считываем заключительные состояния
    vector<string> final_states;
    string state;
    while (cin >> state && state != "END") {
        final_states.push_back(state);
    }

    // считываем начальное состояние и входную строку
    string current_state, input;
    cin >> current_state >> input;

    // запускаем автомат
    int i = 0;
    for (; i < input.length(); ++i) {
        if (transitions[current_state].count(input[i])) {
            current_state = transitions[current_state][input[i]];
        } else {
            break;
        }
    }

    // выводим результат
    if (i == input.length() && find(final_states.begin(), final_states.end(), current_state) != final_states.end()) {
        cout << "1 " << i << " " << current_state << endl;
    } else {
        cout << "0 " << i << " " << current_state << endl;
    }

    return 0;
}