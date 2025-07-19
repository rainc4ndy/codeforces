#include <bits/stdc++.h>
#include <functional>
using namespace std;

#define mod (100001)
#define ll long long
#define x first
#define y second
typedef pair<ll, ll> P;

P v[mod] {};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin >> t;

	ll n;
	vector<ll> ans(t);

	ll x, y;
	for (int i = 0; i < t; i++) {
		cin >> n;

		for (int j = 0; j < n; j++) {
			cin >> x >> y;
			v[j] = {x, y};
		}

		sort(v, v + n);
		ll l = 0, r = n - 1;
		ll p = 0;
		ll stock = 0;
		while (l < r) {

			stock += min(v[r].y, v[l].y);
			v[l].y -= stock;
			p -= v[l].x * stock;
			if (!v[l].y)
				l++;

			ll tmp = v[r].y;
			ll o = stock;
			v[r].y = max(0ll, v[r].y - stock);
			stock = max(0ll, stock - tmp);
			p += v[r].x * (o - stock);
			if (!v[r].y)
				r--;

			//cout << "p = " << p << endl;
		}

		ans[i] = p;
	}

	for (int i = 0; i < t; i++) {
		cout << ans[i];
		if (i != t - 1)
			cout << endl;
	}

	return 0;
}