#include <bits/stdc++.h>
#include <iostream>
#include <iterator>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	int c, l, x, y;
	cin >> c >> l;

	vector<P> v(c);
	map<int, int> d;

	for (int i = 0; i < c; i++) {
		cin >> v[i].x >> v[i].y;
	}
	for (int i = 0; i < l; i++) {
		cin >> x >> y;
		d[x] += y;
	}

	sort(begin(v), end(v), [&](P & a, P & b) {
		if (a.x == b.x)
			return a.y > b.y;
		return a.x > b.x;
	});

	int ans = 0;
	for (int i = 0; i < c; i++) {
		for (auto it = rbegin(d); it != rend(d); it++) {
			if (it->x >= v[i].x &&
			    it->x <= v[i].y &&
			    it->y) {
				--(it->y);
				ans++;
				break;
			}
		}
	}
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int _ = 1;
	while (_--) solve();
	return 0;
}