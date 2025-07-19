#include <bits/stdc++.h>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<ll, ll> P;

void solve() {
	int n;
	cin >> n;

	vector<P> d(n);
	auto cmp_y = [&](P & a, P & b) -> bool {
		if (a.y == b.y)
			return a.x < b.x;
		return a.y < b.y;
	};

	auto cmp_x = [&](P & a, P & b) -> bool {
		if (a.x == b.x)
			return a.y < b.y;
		return a.x < b.x;
	};

	for (int i = 0; i < n; i++) {
		cin >> d[i].x >> d[i].y;
	}

	sort(begin(d), end(d), cmp_y);

	bool flag = false;
	for (int i = 1;i < n; i++) {
		if (d[i].x < d[i-1].x) {
			flag = true;
		}
	}
	if (flag) {
		sort(begin(d), end(d), cmp_x);
		int ans = d[0].x;
		for (int i = 1; i < n; i++) {
			if (d[i].y >= ans)
				ans = min(d[i].x, d[i].y);
			else ans = d[i].x;
		}
		cout << ans << endl;
	} else {
		cout << prev(end(d))->y << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int _ = 1;
	while (_--) solve();

	return 0;
}