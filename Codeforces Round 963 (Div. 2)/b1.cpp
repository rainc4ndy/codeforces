#include <bits/stdc++.h>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    int odd_count = 0;
    int even_count = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }
    
    // If all numbers are already of the same parity
    if (odd_count == 0 || even_count == 0) {
        cout << 0 << endl;
        return;
    }
    
    // Calculate the minimum operations needed
    cout << min(odd_count, even_count) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}
