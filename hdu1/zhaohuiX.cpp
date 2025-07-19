#include <bits/stdc++.h> 
#include <climits>
#include <unordered_set>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

ll a[mod], b[mod], c[mod];


void solve() {
    ll n;
    cin >> n;
    
    ll max_b = -LONG_LONG_MAX, min_b = LONG_LONG_MAX, max_c = -LONG_LONG_MAX, min_c = LONG_LONG_MAX;

    std::unordered_set<ll> um;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        max_b = max(max_b, b[i]);
        min_b = min(min_b, b[i]);
        um.insert(b[i]);
    }

    for (int i = 0; i < n; i++) {
        cin >> c[i];
        max_c = max(max_c, c[i]);
        min_c = min(min_c, c[i]);
    }

    ll l = min_c - max_b, r = max_c - min_b;

    ll A = a[0];
    ll ans = 0;
    for (ll y = l; y <= r; y++) {
        //枚举 (C-B)
        bool ok = false;
        if (y % A == 0) {
            // 是否有可能有 C-B = y / A 
            for (int i = 0; i < n; i++) {
                ll C = c[i];
                ll B = C - y;
                //二分搜索B，B是否在b中
                if (um.count(B)) {
                	ok = true;
                	break;
                }
            }
        }
        if (ok) {
        	cout << y / A << endl;
        	break;
        }
    }
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int _;
    cin >> _;
    while (_--) solve();

    return 0;
}