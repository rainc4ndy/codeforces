#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
typedef long long ll;

void solve() {
    ll n, m, k, p;
    cin >> n >> m >> k >> p;

    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));

    // 初始条件：当步数为0时，只有 p 位置为1，其他都为0
    dp[p][0] = 1;

    for (ll step = 1; step <= k; step++) {
        for (ll i = 1; i <= n; i++) {
            dp[i][step] = 0;
            if (i > 1) 
                dp[i][step] = (dp[i][step] + dp[i - 1][step - 1]) % mod;
            if (i < n) 
                dp[i][step] = (dp[i][step] + dp[i + 1][step - 1]) % mod;
        }
    }

    cout << dp[m][k] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}
