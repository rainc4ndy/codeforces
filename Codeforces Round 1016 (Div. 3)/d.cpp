#include <bits/stdc++.h> 
using namespace std;

#define rep(n) for (int _i_i_ = (n); _i_i_; --_i_i_)
#define mem(arr, x) memset((arr), x, sizeof (arr))
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define random rnd(chrono::system_clock::now().time_since_epoch().count())
#define setdb(v) setprecision(v)
#define debug(x) cout << #x << ' ' << x << endl;
#define x first
#define y second
#define YES cout << "YES\n"
#define Yes cout << "Yes\n"
#define NO cout << "NO\n"
#define No cout << "No\n"
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5+10;
const ll mod = 998244353;

ull findVal(ull tr, ull tc, ull size, ull start, ull x, ull y) {
    if (size == 2) {
        ull val[2][2] = {
            {start,       start + 3},
            {start + 2,   start + 1}
        };
        return val[x - tr][y - tc];
    }
    ull s = size / 2;
    ull block = s * s;
    if (x < tr + s && y < tc + s)
        return findVal(tr, tc, s, start, x, y);                   // 左上
    else if (x >= tr + s && y >= tc + s)
        return findVal(tr + s, tc + s, s, start + block, x, y);     // 右下
    else if (x >= tr + s && y < tc + s)
        return findVal(tr + s, tc, s, start + 2 * block, x, y);     // 左下
    else  
        return findVal(tr, tc + s, s, start + 3 * block, x, y);     // 右上
}

pii findPos(ull tr, ull tc, ull size, ull start, ull d) {
    if (size == 2) {
        ull val[2][2] = {
            {start,       start + 3},
            {start + 2,   start + 1}
        };
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                if (val[i][j] == d)
                    return {tr + i, tc + j}; 
    }
    ull s = size / 2;
    ull block = s * s;
    if (d <= start + block - 1)
        return findPos(tr, tc, s, start, d);                         // 左上
    else if (d <= start + 2 * block - 1)
        return findPos(tr + s, tc + s, s, start + block, d);           // 右下
    else if (d <= start + 3 * block - 1)
        return findPos(tr + s, tc, s, start + 2 * block, d);           // 左下
    else
        return findPos(tr, tc + s, s, start + 3 * block, d);           // 右上
}

void solve() {
    ull n, q;
    cin >> n >> q;
    ull size = 1ULL << n; // 2^n
    while (q--) {
        string cmd;
        cin >> cmd;
        if (cmd == "->") {
            ull x, y;
            cin >> x >> y;
            cout << findVal(0, 0, size, 1, x - 1, y - 1) << "\n";
        } else {
            ull d;
            cin >> d;
            pii pos = findPos(0, 0, size, 1, d);
            cout << pos.x + 1 << " " << pos.y + 1 << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
