#include <bits/stdc++.h>
#include <ios>
#include <queue>
#include <vector>
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
#define x first
#define y second
#define YES cout << "YES\n"
#define Yes cout << "Yes\n"
#define NO cout << "NO\n"
#define No cout << "No\n"
#define zfc(s) cout << #s << '\n'
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;


void solve() {
	ll n, m;
	cin >> n >> m;

	vector<ll> a(m);
	vector<vector<ll>> c(n, vector<ll>(m));
	vector<vector<ll>> w(n, vector<ll>(m));
	vector<bool> vis(n+1);

	for (int i = 0; i < m; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> c[i][j];
		for (int j = 0; j < m; j++)
			cin >> w[i][j];
	}

	int cnt = 0;
	while (true) {
		int pre = cnt;
		for (int i = 0; i < n; i++) {
			if (vis[i])
				continue;
			bool ok = true;
			for (int j = 0; j < m; j++) {
				if (a[j] < c[i][j]) {
					ok = false;
					break;
				}
			}
			if (ok) {
				for (int j = 0; j < m; j++) {
					a[j] += w[i][j];
				}
				cnt++;
				vis[i] = true;
			}
		}
        if (cnt == n) break;
        if (cnt == pre) break;
    }
    if (cnt == n) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

}

int main() {
	fastio;

	int _;
	cin >> _;
	while (_--) solve();

	return 0;
}