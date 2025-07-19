#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> even;
    ll maxOdd = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            even.push_back(a[i]);
        } else {
            maxOdd = max(maxOdd, a[i]);
        }
    }

    if (even.empty() || maxOdd == -1) {
        cout << 0 << endl;
        return;
    }


    sort(even.begin(), even.end());

    ll ans = 0;
    for (ll num : even) {
        if (num < maxOdd) {
            ans++;
            maxOdd += num;
        } else {
            ans += 2;
            maxOdd += num * 2;
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
