#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<array<ll, 3>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    ll left = m, right = m, prev_time = 0;
    
    for (int i = 0; i < n; i++) {
        ll t = v[i][0], l = v[i][1], h = v[i][2];
        ll dt = t - prev_time;
        
        left -= dt;
        right += dt;
        
        if (right < l || left > h) {
            cout << "NO\n";
            return;
        }

        left = max(left, l);
        right = min(right, h);
        prev_time = t;
    }
    
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
