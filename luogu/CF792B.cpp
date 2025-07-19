#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> v(n), ans(k);
	iota(v.begin(), v.end(), 1);

	int a, b = 0;
	for(unsigned i = 0; i < k; ++i) {
		cin >> a;
		b = (b + a) % v.size();

		ans[i] = v[b];
		v.erase(v.begin()+b);
	}

	for(unsigned i = 0; i < k; ++i) {
		cout << ans[i];
		if (i != k - 1)
			cout << ' ';
	}

	return 0;
}
