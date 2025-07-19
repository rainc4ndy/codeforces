#include <bits/stdc++.h>
#include <cstdio>

using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
#define x first
#define y second

#define debug(x) cout << #x << ' ' << x << endl

/*
1
3 4 6
1 2
2 1 1
2 2 2
3 3 2
2 3 2
2 1 2
*/


/*
1
3 4 7
1 2
2 1 1
2 2 2
3 3 2
2 3 2
2 1 2
1 1
*/

void solve() {
	ll n,m,q;
	cin >> n >> m >> q;

	ll active = -1;
	//id,sc
	vector<pll> ans(m);
	ll score = 0;
	unordered_set<ll> finished;
	for (int i = 0; i < m; i++) {
		ans[i].x = i+1; 
	}
	for (int i =0; i < q; i++) {
		int op;
		cin >> op;
		if (op == 1) {	
			ll x;
			cin >> x;
			active = x;
			score = m;
			finished.clear();
		} else {
			ll id, x;
			cin >> id >> x;
			id--;
			if (x != active) continue;
			if (op == 2) {
				if (finished.count(id)) 
					continue;
				finished.insert(id);
				ans[id].y += score;
				score--;
			} else {
				if (finished.count(id)) 
					continue;
				finished.insert(id);
			}
		}
	}
	sort(begin(ans), end(ans), [&](pll&a, pll&b) {
		if (a.y == b.y) {
			return a.x < b.x;
		}
		return a.y > b.y;
	});
	for (auto&it : ans) {
		cout << it.x << ' ' << it.y << endl; 
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int _;
	cin >> _;
	while (_--) {
		solve();
	}
	return 0;
}