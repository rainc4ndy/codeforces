#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // Redistribute probabilities from right to left
    for (int i = n; i > 1; --i) {
        int transfer = min(a[i] - 1, 100 - a[i - 1]); // Transfer as much as possible to make a[i-1] closer to 100
        a[i] -= transfer;
        a[i - 1] += transfer;
    }

    // Calculate the product of probabilities
    ll product = 1;
    for (int i = 1; i <= n; ++i) {
        product = product * a[i];
    }


    ll result = product;
    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
