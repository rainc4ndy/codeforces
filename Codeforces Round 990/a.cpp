#include <bits/stdc++.h>
#include <cmath>
#include <vector>
using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0 ; i < n; i++) cin >> v[i];

	int sum = 0, ans = 0, trg = 2;
	for (int i = 0; i < n; i++) {
		sum += v[i];
		if (sum == 1 && i == 0) {
			trg++;
			ans++;
			sum = 0;
			continue;
		}
		cout << "sum = " << sum << endl;
		if (sum == pow(2, trg)) {
			trg++;
			ans++;
			sum = 0;
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