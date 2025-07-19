#include <bits/stdc++.h> 
#include <iterator>
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
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	bool all_zero = true;
	for (int i = 0; i < n; i++) {
		if (v[i] != 0) 
			all_zero = false;
	}
	if (all_zero) {
		cout << 1 << endl;
		cout << 1 << ' ' << n << endl;
		return;
	}

	bool only_non_zero = false;
	for (int i = 0; i < n -1; i++) {
		if (v[i] != 0) {
			only_non_zero = true;
		} else {
			only_non_zero = false;
			break;
		}
	}
	if (only_non_zero && v[n-1] == 0) {
		cout << 2 << endl;
		cout << n-2 << ' ' << n-1 << endl;
		cout << 1 << ' ' << n-2 << endl;
		return;
	}

	if (only_non_zero && v[n-1] != 0) {
		cout << 1 << endl;
		cout << 1 << ' ' << n << endl;
	}

	vector<pii> ans; 
	int cnt = 0;
	bool bad = false;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 0) {	
			if (i+1 < v.size() && v[i+1] != 0) {
				ans.push_back({i-cnt, i+1-cnt});
				cnt += 1;
			} else {
				int j = i;
				while (j + 1 < v.size() && v[j+1] == 0) j++;

				{
					ans.push_back({i-cnt, j-cnt});
					cnt += j-i+1;
					i = j+1;					
				}
			}
		}
	}
	ans.push_back({0, v.size()-cnt});
	cout << ans.size() << endl;
	for (int i =0; i < ans.size(); i++) {
		cout << ans[i].x + 1 << ' '  << ans[i].y + 1<< endl;
	}
}

int main() {    
    fastio;
	int _;
	cin >> _;
	while(_--) solve();

	return 0;
}