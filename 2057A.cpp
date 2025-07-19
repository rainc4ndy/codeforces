#include <bits/stdc++.h>
 
using i64 = long long;
 
void solve() {
    int n, m;
    std::cin >> n >> m;
    std::cout << std::max(n, m) + 1 << "\n";
}
 
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t = 1;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
}