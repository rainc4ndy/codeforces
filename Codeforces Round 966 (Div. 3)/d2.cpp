#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        string s;
        cin >> s;

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + a[i];
        }

        long long max_score = 0;
        int left = -1;
        vector<int> R_indices;

        for (int i = 0; i < n; ++i) {
            if (s[i] == 'R') {
                R_indices.push_back(i);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (s[i] == 'L') {
                while (!R_indices.empty() && R_indices.back() <= i) {
                    R_indices.pop_back();
                }

                if (!R_indices.empty()) {
                    int r = R_indices.back();
                    long long sum = prefix[r + 1] - prefix[i];
                    max_score += sum;
                    R_indices.pop_back(); // Use this 'R'
                }
            }
        }

        cout << max_score << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
