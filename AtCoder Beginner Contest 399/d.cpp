#include <bits/stdc++.h> 
#include <unordered_map>
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
const int maxn = 2e5+10;
const ll mod = 998244353;

void solve() {
	int n;
	cin >> n;

	vector<int> v(2*n);
	unordered_map<int, pii> um;
	map<int, int> st; 
	set<int> s;

	for (int i = 0; i < 2*n; i++) {
		cin >> v[i];
		if (!st[v[i]]) {
			um[v[i]].x = i;
		} else {
			um[v[i]].y = i;
		}
		st[v[i]]++;
		s.insert(v[i]);
	}

	set<pii> ans;
	for (auto it : s) {
		int p1 = um[it].x, p2 = um[it].y;

		if (abs(p1-p2) == 1)
			continue;

		int a = -1,b = -1,c = -1,d = -1;
		if (p1 - 1 >= 0) a = v[p1-1];
		if (p1 + 1 < 2*n) b = v[p1+1];
		if (p2 - 1 >= 0) c = v[p2-1];
		if (p2 + 1 < 2*n) d = v[p2+1];

		map<int, int> tmp;
		tmp[a]++;
		tmp[b]++;
		tmp[c]++;
		tmp[d]++;

		bool ok = false;
		for (auto yt : tmp) {
			if (yt.x != -1 && yt.y > 1) {
				ans.insert(
					{
						min(yt.x, it),
						max(yt.x, it)
					});
				ok = true;
				break;
			}
		}
	}
	cout << ans.size() << endl;
}

int main() {    
    fastio;
	int _;
	cin >> _;
	while(_--) solve();

	return 0;
}