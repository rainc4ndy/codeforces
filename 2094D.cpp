#include <bits/stdc++.h>
#include <cmath>
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
	string s1, s2;
	cin >> s1 >> s2;

	int c1 = 0 , c2 = 0;
		for (auto c : s1) if (c == 'L') c1++; else c2++;

	auto work = [&](string s) -> vector<pair<char,int>> {
		vector<pair<char,int>> res;
		int l = 0, r = 0;
		while (r < s.size()) {
			while (r + 1 < s.size() && s[r + 1] == s[l]) {
				r++;
			}
			int sz = r - l + 1;
			res.emplace_back(s[l], sz);
			r++;
			l = r;
		}
		return res;
	};

	auto v1 = work(s1), v2 = work(s2);

	if (v1.size() != v2.size()) {
		NO;
		return;
	}

	for (int i = 0; i < v1.size(); i++) {
		if (v1[i].y > v2[i].y) {
			NO;
			return;
		}
		if (v1[i].x != v2[i].x) {
			NO;
			return;
		}
		if (v1[i].y < ceil((double)v2[i].y / 2.0)) {
			NO;
			return;
		}
	}
	YES;
}

int main() {
	fastio;
	int _;
	cin >> _;
	while (_--) solve();

	return 0;
}