#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        int m;
        cin >> m;

        vector<int> d(m);
        unordered_map<int, int> d_count;
        for (int i = 0; i < m; ++i) {
            cin >> d[i];
            d_count[d[i]]++;
        }

        unordered_map<int, int> needed_changes;
        bool possible = true;

        // Count the required changes
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                needed_changes[b[i]]++;
            }
        }

        // Verify if we can meet the required changes with d
        for (const auto& change : needed_changes) {
            if (d_count[change.first] < change.second) {
                possible = false;
                break;
            }
        }

        if (possible) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
