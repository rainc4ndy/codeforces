#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
ll encode(ll x, ll y) {
    return x * 1000003LL + y;
}
unordered_map<char, pair<int,int>> dir = {
    {'N', {-1, 0}},
    {'W', {0, -1}},
    {'S', {1, 0}},
    {'E', {0, 1}}
};
 
void solve(){
    int n, R, C;
    cin >> n >> R >> C;
    string S;
    cin >> S;
    
    vector<ll> px(n+1, 0), py(n+1, 0);
    px[0] = 0; py[0] = 0;
    
    unordered_set<ll> seen;
    seen.insert(encode(0, 0));
    
    string ans;
    for (int t = 1; t <= n; t++){
        px[t] = px[t-1] + dir[S[t-1]].first;
        py[t] = py[t-1] + dir[S[t-1]].second;
        
        ll target_x = px[t] - R;
        ll target_y = py[t] - C;
        
        if(seen.count(encode(target_x, target_y))) {
            ans.push_back('1');
        } else {
            ans.push_back('0');
        }
        seen.insert(encode(px[t], py[t]));
    }
    
    cout << ans << "\n";
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}
