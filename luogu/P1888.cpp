#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll mx = numeric_limits<ll>::min(),
        mi = numeric_limits<ll>::max();

    ll tmp = 0;
    for (int i = 0; i < 3; i++) {
        cin >> tmp;
        mi = min(tmp, mi);
        mx = max(tmp, mx);
    }

    ll g = gcd(mx, mi);

    cout << (mi/g) << '/' << (mx/g);

    return 0;
}
