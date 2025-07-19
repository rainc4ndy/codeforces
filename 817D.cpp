#include <bits/stdc++.h>
#include <stack>
#include <vector>
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
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> Lmax(n), Rmax(n), Lmin(n), Rmin(n);

    // 左边第一个比它大的
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && v[st.top()] <= v[i]) st.pop();
        Lmax[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    // 右边第一个比它大的
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && v[st.top()] < v[i]) st.pop();
        Rmax[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    // 左边第一个比它小的
    while (!st.empty()) st.pop();
    for (int i = 0; i < n; i++) {
        while (!st.empty() && v[st.top()] >= v[i]) st.pop();
        Lmin[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    // 右边第一个比它小的
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && v[st.top()] > v[i]) st.pop();
        Rmin[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll max_contrib = v[i] * (i - Lmax[i]) * (Rmax[i] - i);
        ll min_contrib = v[i] * (i - Lmin[i]) * (Rmin[i] - i);
        ans += max_contrib - min_contrib;
    }
    cout << ans << "\n";
}

int main() {
	fastio;
	int _ = 1;
	while (_--) solve();

	return 0;
}