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

bool ok(int x, const vector<int>& freq, int k) {
    int sets = INT_MAX;
    for (int i = 0; i < x; ++i) {
        sets = min(sets, freq[i]);
    }
    return sets >= k;
}

void solve() {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int& val : a) cin >> val;

        vector<int> freq(n + 2, 0); 
        for (int val : a) {
            if (val <= n) freq[val]++;
        }

        int left = 0, right = n + 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (ok(mid, freq, k)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        cout << left - 1 << '\n';
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
