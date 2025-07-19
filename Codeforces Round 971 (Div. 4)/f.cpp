#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n, k;
    cin >> n >> k;
    
    // Calculate the difference between the sums when split in the middle
    ll mid = n / 2;
    ll sum1 = k * mid + mid * (mid - 1) / 2;         // Sum of the first half
    ll sum2 = k * (n - mid) + (n - mid) * (n - mid - 1) / 2;  // Sum of the second half

    cout << "sum1 = " << sum1 << endl;
    cout << "sum2 = " << sum2 << endl;
    
    ll x = abs(sum1 - sum2);
    cout << x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}
