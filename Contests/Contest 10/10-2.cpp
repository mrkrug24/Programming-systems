#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // read transitions
    string cur, chr, new_;
    vector<pair<pair<string, char>, string>> transitions;
    while (cin >> cur && cur != "END") {
        cin >> chr >> new_;
        transitions.emplace_back(make_pair(cur, chr[0]), new_);
    }

    // read final states
    vector<string> final_states;
    while (cin >> cur && cur != "END") {
        final_states.push_back(cur);
    }

    // read initial state and input string
    string initial_state, input;
    cin >> initial_state >> input;

    // simulate DFA
    string current_state = initial_state;
    int input_read = 0;
    for (char c : input) {
        auto it = find(transitions.begin(), transitions.end(), make_pair(current_state, c));
        if (it == transitions.end()) {
            break;
        }
        current_state = it->second;
        ++input_read;
    }

    // output result
    cout << (find(final_states.begin(), final_states.end(), current_state) != final_states.end()) << " " << input_read << " " << current_state << endl;

    return 0;
}