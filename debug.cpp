#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll a;
    cin >> a;

    ll ans = 1;
    for (ll i = 1; i * i <= a; i++) {
        if (a % i == 0) {
            if (i < a) ans = max(ans, i);
            if (a / i < a) ans = max(ans, a / i);
        }
    }

    cout << ans << endl;
    return 0;
}
