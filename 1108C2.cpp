#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<string> patterns = {"RGB", "RBG", "GRB", "GBR", "BRG", "BGR"};
    int min_changes = INT_MAX;
    string best_pattern;

    for (const string& pattern : patterns) {
        string current_pattern;
        for (int i = 0; i < n; ++i) {
            current_pattern += pattern[i % 3];
        }

        int changes = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] != current_pattern[i]) {
                ++changes;
            }
        }

        if (changes < min_changes) {
            min_changes = changes;
            best_pattern = current_pattern;
        }
    }

    cout << min_changes << '\n';
    cout << best_pattern << '\n';

    return 0;
}
