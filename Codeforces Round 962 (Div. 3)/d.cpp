#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

void solve() {
    int n, x;
    cin >> n >> x;

    ll ans = 0;
    for (int a = 1; a <= x; a++) {
        for (int b = 1; b <= x - a; b++) {
            int max_c = x - a - b;
            
            int max_c_ab = (n - a * b) / (a + b);
            max_c = min(max_c, max_c_ab);

            if (max_c > 0) {
                ans += max_c;
            }
        }
    }

    cout << ans << "\n";
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
