#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;
const int MAXN = 1e5;

ll fac[MAXN + 1], invFac[MAXN + 1];

// 快速幂计算 (x^y) % m
ll power(ll x, ll y, ll m) {
    ll result = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            result = (result * x) % m;
        }
        x = (x * x) % m;
        y /= 2;
    }
    return result;
}

// 预计算阶乘和阶乘的模逆元
void prefac(int n, ll m) {
    fac[0] = fac[1] = 1;
    for (int i = 2; i <= n; ++i) {
        fac[i] = fac[i - 1] * i % m;
    }
    invFac[n] = power(fac[n], m - 2, m);
    for (int i = n - 1; i >= 0; --i) {
        invFac[i] = invFac[i + 1] * (i + 1) % m;
    }
}

// 计算组合数 C(n, k) % m
ll com(int n, int k, ll m) {
    if (k > n) return 0;
    return fac[n] * invFac[k] % m * invFac[n - k] % m;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int a, b, k, c;
    cin >> a >> b >> k >> c;

    if (a != c && b != c) {
        cout << 0;
        return 0;
    }
    if (a == c && b == c) {
        cout << k;
        return 0;
    }

    prefac(MAXN, mod);

    ll ans = 0;
    for (int i = 1; i <= k; i++) {
        ll r = com(k, i, mod);
        ans = (ans + r * i % mod) % mod;
    }
    cout << ans;
    return 0;
}
