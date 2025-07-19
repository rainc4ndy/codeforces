#include <bits/stdc++.h>
using namespace std;

#define rep(n) for (int _i_i_ = (n); _i_i_; --_i_i_)
#define mem(arr, x) memset((arr), x, sizeof (arr))
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define import mt19937
#define random rnd(chrono::system_clock::now().time_since_epoch().count())
#define setdb(v) setprecision(v)
#define debug(x) cout << #x << ' ' << x << endl;
#define fi first
#define se second
#define YES cout << "YES\n"
#define Yes cout << "Yes\n"
#define NO cout << "NO\n"
#define No cout << "No\n"
#define zfc(s) cout << #s << '\n'
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 1e6 + 5;

int n, m;
int op, a, b;
int fa[maxn], p[maxn], q[maxn], r[maxn];

int find(int i) {
    return fa[i] == i ? i : fa[i] = find(fa[i]);
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) fa[i] = p[i] = q[i] = r[i] = i;
    rep (m) {
        cin >> op >> a;
        if (op != 4) cin >> b;
        if (op == 1) {
            fa[find(r[b])] = find(r[a]);
        } else if (op == 2) {
            p[a] = find(r[b]);
        } else if (op == 3) {
            swap(q[r[a]], q[r[b]]);
            swap(r[a], r[b]);
        } else {
            cout << q[find(p[a])] << '\n';
        }
    }
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    rep (t) {
        solve();
    }
    return 0;
}