#include <bits/stdc++.h> 
#include <functional>
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

#define int ll

void solve() {
	int n;
	cin >> n;
	vector<int> u(n), s(n);
	unordered_map<int, vector<int>> um;
	unordered_map<int, vector<int>> pa;


	for (int i = 0; i < n; i++) {
		cin >> u[i];
	} 	
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		um[u[i]].push_back(s[i]);
	} 		

	for (auto& it : um) {
		sort(begin(it.y), end(it.y), std::greater<int>());

		auto& arr = pa[it.x];
		arr.resize(it.y.size() + 1);
		arr[0] = it.y[0];
		for (int i = 1; i < it.y.size(); i++) {
			arr[i] = arr[i-1] + it.y[i];
		}
	}

	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (auto& it : um) {
			int r = it.y.size() % i;
			int rr = it.y.size()-1 - r;
			sum += rr >= 0 ? pa[it.x][it.y.size()-1 - r] : 0;
		}
		cout << sum << ' ';
	}
	cout << endl;
}

signed main() {    
    fastio;
	int _;
	cin >> _;
	while(_--) solve();

	return 0;
}