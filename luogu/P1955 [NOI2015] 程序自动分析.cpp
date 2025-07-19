#include <bits/stdc++.h>
using namespace std;

#define ll long long
unordered_map<ll, ll> pa;
ll find(ll i) {
	return pa[i] == i ? i : (pa[i] = find(pa[i]));
}
void unite(ll i, ll j) {
	pa[find(i)] = find(j);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n, e;
	ll i, j;
	cin >> t;

	vector<int> ans(t, true);
	vector<pair<ll, ll>> pending;

	for (int x = 0; x < t; x++) {
		cin >> n;
		pa.clear();
		pending.clear();
		for (int y = 0; y < n; y++) {
			cin >> i >> j >> e;
			if (!pa[i])
				pa[i] = i;
			if (!pa[j])
				pa[j] = j;

			if (e == 1) {
				unite(i, j);
			} else {
				pending.emplace_back(make_pair(i, j));
			}
		}
		for (auto it : pending) {
			if (find(it.first) == find(it.second)) {
				ans[x] = false;
				break;
			}
		}
	}

	for (int x = 0; x < t; x++) {
		cout << (ans[x] ? "YES" : "NO");
		if (x != t - 1)
			cout << endl;
	}

	return 0;
}
