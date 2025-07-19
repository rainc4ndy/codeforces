#include <algorithm>
#include <bits/stdc++.h> 
#include <functional>
#include <iterator>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for (int i = 0; i < m; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        
        ll ans = 0;
        for (int k = 1; k < n; k++){
            int l = m - (int)(lower_bound(a.begin(), a.end(), k) - a.begin());
            int r = m - (int)(lower_bound(a.begin(), a.end(), n - k) - a.begin());
            int g = m - (int)(lower_bound(a.begin(), a.end(), max(k, n - k)) - a.begin());
            ans += (ll)l * r - g;
        }
        cout << ans << "\n";
    }
    return 0;
}
