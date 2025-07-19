#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;

    unordered_map<ll, int> count_x;  // 记录可能的 x 及其出现次数

    for (int i = 0; i < n; i++) {
        ll u, v, w;
        cin >> u >> v >> w;

        ll p[6][3] = {
            {u, v, w}, {u, w, v}, {v, u, w}, 
            {v, w, u}, {w, u, v}, {w, v, u}
        };

        for (int j = 0; j < 6; j++) {
            ll a = p[j][0], b = p[j][1], c = p[j][2];
            if ((c - b) % a == 0) {
                ll x = (c - b) / a;
                if (x >= 0)
	                count_x[x]++;
            }
        }

        int zero_cnt = 0;
        for (int j = 0; j < 6; j++) {
        	ll a = p[j][0], b = p[j][1], c = p[j][2];
        	if (a * 0 + b == c) {
        		zero_cnt++;
        	}
        }
        if (zero_cnt == 6) {
        	cout << 0 << endl;
        	return;
        }
    }

    for (auto &p : count_x) {
        if (p.second == n) { // 找到唯一满足所有方程的 x
            cout << p.first << endl;
            return;
        }
    }
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}
