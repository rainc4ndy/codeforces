#include <bits/stdc++.h>
using namespace std;

#define rep(n) for (int _i_i_ = (n); _i_i_; --_i_i_)
#define mem(arr, x) memset((arr), x, sizeof (arr))
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define random rnd(chrono::system_clock::now().time_since_epoch().count())
#define setdb(v) setprecision(v)
#define all(x) x.begin(), x.end()
#define unq_all(x) x.erase(unique(all(x)), x.end())
#define sort_all(x) sort(all(x))
#define reverse_all(x) reverse(all(x))
#define x first
#define y second
#define YES cout << "YES\n"
#define Yes cout << "Yes\n"
#define NO cout << "NO\n"
#define No cout << "No\n"
#define pb push_back
#define eb emplace_back
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
const ll mod = 998244353;
#define RED cout << "\033[91m"
#define GREEN cout << "\033[92m"
#define YELLOW cout << "\033[93m"
#define BLUE cout << "\033[94m"
#define MAGENTA cout << "\033[95m"
#define CYAN cout << "\033[96m"
#define RESET cout << "\033[0m"
#define debug(x) cout << #x << ' ' << x << endl;
#define debug1(x)                     \
    RED;                              \
    cout << #x << ' ' << x << endl; \
    RESET;
#define debug2(x)                     \
    GREEN;                            \
    cout << #x << ' ' << x << endl; \
    RESET;
#define debug3(x)                     \
    BLUE;                             \
    cout << #x << ' ' << x << endl; \
    RESET;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    bool has05 = false, hasOther = false;

    for (auto &x : a) {
        cin >> x;
        if (x % 10 == 0 || x % 10 == 5) has05 = true;
        else hasOther = true;
    }

    if (has05 && hasOther) {
        cout << "NO\n";
        return;
    }

    if (has05) {
        for (auto &x : a) {
            if (x % 10 == 5) x += 5;
        }
        if (count(a.begin(), a.end(), a[0]) == n) cout << "YES\n";
        else cout << "NO\n";
        return;
    }

    for (auto &x : a) {
        while (x % 10 != 2) {
            x += x % 10;
        }
    }

    ll base = a[0] % 20;
    for (auto &x : a) {
        if (x % 20 != base) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) solve();
}
