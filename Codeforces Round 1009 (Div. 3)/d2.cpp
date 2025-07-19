#include <bits/stdc++.h>
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
        vector<ll> centers(n), radii(n);
        for (int i = 0; i < n; i++) cin >> centers[i];
        for (int i = 0; i < n; i++) cin >> radii[i];
 
        unordered_map<ll, vector<pair<int,int>>> mp;
        mp.reserve(n * 2);
 
        for (int i = 0; i < n; i++){
            ll cx = centers[i];
            int r = radii[i];
            for (int dx = -r; dx <= r; dx++){
                ll X = cx + dx;
                int y_max = (int)floor(sqrt((long double)r * r - (ll)dx * dx));
                mp[X].push_back({-y_max, y_max});
            }
        }
 
        ll ans = 0;
        for(auto &entry : mp){
            auto &intervals = entry.second;
            sort(intervals.begin(), intervals.end());
            int curL = intervals[0].first, curR = intervals[0].second;
            ll cnt = 0;
            for (size_t i = 1; i < intervals.size(); i++){
                int L = intervals[i].first, R = intervals[i].second;
                if (L <= curR + 1) {
                    curR = max(curR, R);
                } else {
                    cnt += (ll)(curR - curL + 1);
                    curL = L;
                    curR = R;
                }
            }
            cnt += (ll)(curR - curL + 1);
            ans += cnt;
        }
        cout << ans << "\n";
    }
    return 0;
}
