#include <bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(), (a).end()
#define int long long
const int inf = 1e18;


bool check(vector<int> a, int k, int x) {
    int n = a.size();
    vector<bool> seen(x);
    int j = 0;
    int s = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < x) {
            seen[a[i]] = 1;
        }
        while (j < x && seen[j]) {
            j += 1;
        }
        if (j == x) {
            s += 1;
            j = 0;
            seen = vector<bool>(x, 0);
        }
    }
    return s >= k;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int l = 0;
    int r = n + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (check(a, k, m)) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();    
    }
}