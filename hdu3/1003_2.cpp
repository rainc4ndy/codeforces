#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    unordered_map<ll, int> status, pos;
    unordered_set<ll> um;
    
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) {
            for (auto it : um) {
                if (status[it] == 0) {
                    status[it] = 1;
                }
            }
            um.clear();
        } else {
            if (status[v[i]] == 0) {
                um.insert(v[i]);
            }
            else if (status[v[i]] == 1) {
                status[v[i]] = 2;
                pos[v[i]] = i;
            }
        }
    }
    
    vector<int> pa(n+1, 0);
    unordered_set<ll> cur;
    pa[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (v[i] == 0) {
            pa[i] = pa[i+1];
        } else {
            if (cur.find(v[i]) == cur.end()) {
                cur.insert(v[i]);
                pa[i] = pa[i+1] + 1;
            } else {
                pa[i] = pa[i+1];
            }
        }
    }
    
    ll ans = 0;
    for (auto &[x, s] : status) {
        if (s == 2) {
            ans += pa[pos[x] + 1];
        }
    }
    cout << ans << "\n";
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
