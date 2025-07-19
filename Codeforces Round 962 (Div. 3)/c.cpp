#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    string a, b;
    cin >> a >> b;

    vector<vector<int>> freq_a(n + 1, vector<int>(26, 0));
    vector<vector<int>> freq_b(n + 1, vector<int>(26, 0));

    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            for (int j = 0; j < 26; ++j) {
                freq_a[i + 1][j] = freq_a[i][j];
                freq_b[i + 1][j] = freq_b[i][j];
            }
        }
        freq_a[i + 1][a[i] - 'a']++;
        freq_b[i + 1][b[i] - 'a']++;
    }

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        int p1 = 0, p2 = 0;
        for (int j = 0; j < 26; ++j) {
            int count_a = freq_a[r + 1][j] - freq_a[l][j];
            int count_b = freq_b[r + 1][j] - freq_b[l][j];
            if (count_b > count_a) {
                p1 += count_b - count_a;
            } else if (count_a > count_b) {
                p2 += count_a - count_b;
            }
        }
        cout << min(p1, p2) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
