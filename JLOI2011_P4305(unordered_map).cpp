#include <bits/stdc++.h> 
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    long long digit;
    cin >> t;

    vector<vector<long long>> uniqueNumbers(t);

    for (int i = 0; i < t; i++) {
        cin >> n;

        unordered_map<long long, int> counts;

        for (int j = 0; j < n; j++) {
            cin >> digit;
            if (++counts[digit] == 1) {
                uniqueNumbers[i].push_back(digit);
            }
        }
    }

    for (int i = 0; i < t; i++) {
        for (size_t j = 0; j < uniqueNumbers[i].size(); j++) {
            cout << uniqueNumbers[i][j];
            if (j != uniqueNumbers[i].size() - 1) 
                cout << ' ';
        }
        if (i != t - 1)
            cout << '\n';
    }
    return 0;
}
