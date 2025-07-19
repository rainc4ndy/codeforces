#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
typedef long long ll;

void solve() {
    ll n, l, r;
    cin >> n >> l >> r;

    auto f = [&](ll x) {
        return (r - x) / 3 - (l - x - 1) / 3;
    };

    ll a = f(0), // 余数为 0 的数的个数
       b = f(1), // 余数为 1 的数的个数
       c = f(2); // 余数为 2 的数的个数

    vector<array<ll, 3>> dp(n); 
    dp[0] = {a, b, c}; // 初始化第一位的状态

    for (int i = 1; i < n; i++) {
        dp[i][0] = (dp[i-1][0] * a + dp[i-1][1] * c + dp[i-1][2] * b) % mod;
        dp[i][1] = (dp[i-1][0] * b + dp[i-1][1] * a + dp[i-1][2] * c) % mod;
        dp[i][2] = (dp[i-1][0] * c + dp[i-1][1] * b + dp[i-1][2] * a) % mod;
    }

    cout << dp[n-1][0] << '\n';
}

int main() {    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int _ = 1;
    while (_--) solve();

    return 0;
}
