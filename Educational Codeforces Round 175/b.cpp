#include <bits/stdc++.h>
#include <ostream>
#include <vector>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	ll n, x, k;
	cin >> n >> x >> k;

	vector<char> v(n);
	vector<ll> pl(n + 1, 0);
	vector<ll> pr(n + 1, 0);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	ll cur = x, cost = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] == 'R') cur++;
		else cur--;
		cost++;
		if (cur == 0) {
			break;
		}
	}

	if (cur != 0) {
		cout << 0 << endl;
		return;
	}

	k -= cost;
	ll ans = 1;

	pr[0] = (v[0] == 'R');
	pl[0] = (v[0] == 'L');
	for (int i = 1; i < n; i++) {
		pr[i] = pr[i - 1] + (v[i] == 'R');
		pl[i] = pl[i - 1] + (v[i] == 'L');
	}

	for (int i = 0; i < n; i++) {
		if (v[i] == 'R') cur++;
		else cur--;

		if (!cur) {
			ans += k / (i + 1);
			break;
		}
	}
	cout << ans << endl;
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