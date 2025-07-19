#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using ll = long long;
const int maxn = 2e5 + 10;

void solve() {
	ll n;
	cin >> n;  // 读取 n
	vector<ll> v(n);
	set<ll> ss;
	map<ll, ll> m;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		ss.insert(v[i]);
		m[v[i]]++;
	}

	map<ll, ll> m2;

	ll cnt = 1;
	for (auto it = rbegin(ss); it != rend(ss); it++) {
		m2[*it] += cnt;
		cnt += m[*it];
	}

	for (int i = 0; i < n; i++) {
		cout << m2[v[i]] << endl;
	}
}

int main() {
	fastio;
	int _ = 1;
	while (_--) solve();
	return 0;
}
