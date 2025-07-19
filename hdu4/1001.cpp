#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
typedef long long ll;

vector<ll> fs(200002);
void work(int max_n) {
    fs[0] = 1;
    for (int i = 1; i <= max_n; i++) {
        fs[i] = fs[i-1] * i % mod;
    }
}
ll factorial(int n) {
    return fs[n];
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    vector<int> cnt(n);
    ll zs = 0; // how many zero
    for (int i = 0; i < n; i++) {
        if (a[i] & 1) {
            cnt[i] = (c[i] + 1) / 2;
        } else {
            cnt[i] = 0;
            zs++;
        }
    }
   	ll bs = 0;
    for (int i = 0; i < n; i++)  {
        if (!c[i] && a[i] & 1) bs++;
    }
    ll ans = factorial(zs + bs);
    for (int i = 0; i < n; i++) {
         ans = ans * (cnt[i] + 1) % mod;
    }
    
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    work(200000);

    int _; 
    cin >> _;
    while (_--) solve();

    return 0;
}
