#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    string A, B;
    cin >> A >> B;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) a[i] = A[i] - '0';
    for (int i = 0; i < m; i++) b[i] = B[i] - '0';
    int ans = 0;
    for (int i = 0; i + n <= m; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] != b[i + j]) cnt++;
        }
        ans = max(ans, cnt);
    }

    cout << ans << '\n';
}

int main() {
    fastio;
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
