#include <bits/stdc++.h>
#include <cmath>
#include <vector>
using namespace std;

const int mod = 1e8 + 10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	ll n, k;
	cin >> n >> k;

	ll cnt = 0;

	set<ll> ss;
	for (ll i = 1; i*i <= n; i++) {
		if (n % i == 0) {
			ss.insert(i), ss.insert(n/ i);
		}
	}

	cnt = 0;
	for (auto it : ss) {
		cnt += 1;
		if (cnt == k) {
			cout << it;
			return;
		}
	}
	cout << -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int _ = 1;
	while (_--) solve();

	return 0;
}