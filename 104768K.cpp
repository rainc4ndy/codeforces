#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    map<vector<int>, int> mp;
    vector<int> tmp(n + 1);
    vector nums(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> nums[i][j];
        }
    }
    for (int i = 1; i <= m; ++i) {
        map<vector<int>, int> mid(mp);
        mid[nums[i]] = 1;
        for (auto [a, _] : mp) {
            for (int j = 1; j <= n; ++j) {
                tmp[j] = a[nums[i][j]];
            }
            mid[tmp] = 1;
        }
        mp = mid;
    }
    cout << mp.size() << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
