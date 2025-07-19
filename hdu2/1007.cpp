#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

ll mod_pow(ll a, ll b, ll mod) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll solve(ll n) {
    if (n % 2 == 0) {
        return (n % MOD) * ((n + 2) % MOD) % MOD * mod_pow(4, MOD - 2, MOD) % MOD;
    } else {
        return ((n - 1) % MOD) * ((n + 1) % MOD) % MOD * mod_pow(4, MOD - 2, MOD) % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        cout << solve(n) << '\n';
    }

    return 0;
}
