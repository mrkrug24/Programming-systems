#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    // Считывание входных данных
    vector<pair<string, string>> rules;
    string left, right;
    while (cin >> left >> right) {
        rules.emplace_back(left, right);
    }

    // Проверка наличия правил
    if (rules.empty()) {
        cout << -1 << endl;
        return 0;
    }

    // Проверка наличия нетерминала S в левой части правил
    bool has_S = false;
    for (const auto& rule : rules) {
        if (rule.first == "S") {
            has_S = true;
            break;
        }
    }
    if (!has_S) {
        cout << -1 << endl;
        return 0;
    }

    // Проверка на корректность грамматики
    unordered_set<string> nonterminals;
    for (const auto& rule : rules) {
        if (rule.first.empty() || rule.second.empty() ||
            !isupper(rule.first[0]) || rule.first.size() > 1 ||
            (rule.second.size() > 1 && rule.second != "_") ||
            (!isupper(rule.second[0]) && !isdigit(rule.second[0]))) {
            cout << -1 << endl;
            return 0;
        }
        nonterminals.insert(rule.first);
    }

    // Проверка типа грамматики
    bool is_CNF = true;
    bool is_UCNF = true;
    for (const auto& rule : rules) {
        if (rule.second == "_") {
            continue; // Пустая правая часть
        }
        if (rule.second.size() == 1 && isupper(rule.second[0])) {
            is_UCNF = false; // Единственный нетерминал
        } else if (rule.second.size() == 2 && isupper(rule.second[0]) && isupper(rule.second[1])) {
            is_CNF = false; // Два нетерминала
        } else {
            is_CNF = false;
            is_UCNF = false;
            break;
        }
    }

    if (is_UCNF) {
        cout << 23 << endl;
    } else if (is_CNF) {
        cout << 2 << endl;
    } else {
        cout << 10 << endl;
    }

    return 0;
}