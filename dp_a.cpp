#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];

    if (n == 1) {
        cout <<  v[0];
        return;
    } else if (n == 2) {
        cout << max(v[0], v[1]);
        return;
    }

    long long dp[101] {0};
    dp[0] = v[0];
    dp[1] = max((int)dp[0], v[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + v[i]);
    }
    cout << dp[n - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int _ = 1;
    while (_--) solve();

    return 0;
}