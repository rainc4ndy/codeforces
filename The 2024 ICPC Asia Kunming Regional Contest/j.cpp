#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <locale>
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
	int n;
	string s;
	cin >> n >> s;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	auto v2 = v;
	sort(begin(v2), end(v2));
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] != v2[i]) cnt++;
	}

	if (n == 2) {
		cout << "Alice" << endl;
		return;
	} else if (n == 3) {
		int mi = *min_element(begin(v),end(v));
		v[0] -= mi;
		v[1] -= mi;
		v[2] -= mi;
		if (v == vector<int>({0, 1, 2}))cout << "Alice\n";
		else if (v == vector<int>({1, 0, 2})) {
			if (s == "Alice")cout << "Alice\n";
			else cout << "Bob\n";
		}
		else if (v == vector<int>({2, 0, 1})) {
			if (s == "Alice")cout << "Bob\n";
			else cout << "Alice\n";
		}
		else if (v == vector<int>({0, 2, 1})) {
			if (s == "Alice")cout << "Alice\n";
			else cout << "Bob\n";
		}
		else if (v == vector<int>({1, 2, 0})) {
			if (s == "Alice")cout << "Bob\n";
			else cout << "Alice\n";
		}
		else if (v == vector<int>({2, 1, 0})) {
			if (s == "Alice")cout << "Alice\n";
			else cout << "Bob\n";
		}
		return;
	}

	if (cnt == 0) {
		cout << "Alice" << endl;
	} else {
		if (s == "Alice" && cnt == 2) {
			cout << "Alice" << endl;
		} else cout << "Bob" << endl;
	}
}

int main() {
	fastio;
	int _;
	cin >> _;
	while (_--) solve();

	return 0;
}