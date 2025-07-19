#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    string ans;
    int half = (n - (n % 2 == 0 ? 2 : 1)) / 2;
    
    ans.append(half, '-');  
    ans.append(n % 2 == 0 ? "==" : "="); 
    ans.append(half, '-');  

    cout << ans << '\n';
}

int main() {    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
