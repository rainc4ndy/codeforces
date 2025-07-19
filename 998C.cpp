#include <bits/stdc++.h>
#include <vector>
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
const int maxn = 2e5 + 10;
const ll mod = 998244353;

void solve() {
	int k;
	cin >> k;
	vector<vector<int>> v(k);
	vector<int> sum(k);
	for (int i = 0; i < k; i++) {
		int n;
		cin >> n;
		v[i].resize(n);
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
			sum[i] += v[i][j];
		}
	}

	map<int, pii> ss;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			int d = sum[i] - v[i][j];
			if (ss.find(d) != ss.end()) {
				if (ss[d].x != i) {
					YES;
					cout << ss[d].x + 1 << ' ' << ss[d].y + 1 << endl;
					cout << i + 1 << ' ' << j+1 << endl;
					return;
				}
			}
			ss[d] = {i, j};
		}
	}
	NO;
}



int main() {
	fastio;
	int _ = 1;
	while (_--) solve();

	return 0;
}