#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <unordered_set>
#include <vector>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	ll n, m;
	cin >> n >> m;

	unordered_set<ll> s;
	ll tmp;
	ll mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		s.insert(tmp);
		mx = max(tmp, mx);
	}

	vector<ll> v;
	for (auto it : s)
		v.emplace_back(it);

	char c; ll l, r;
	for (int i = 0; i < m; i++) {
		cin >> c >> l >> r;
		if (c == '-') {
			if (l <= mx && mx <= r) {
				mx--;
			}
			cout << mx;
			if (i != m - 1) cout << ' ';
		} else {
			if (l <= mx && mx <= r) {
				mx++;
			}
			cout << mx;
			if (i != m - 1) cout << ' ';
		}
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int _;
	cin >> _;
	while (_--) solve();

	return 0;
}