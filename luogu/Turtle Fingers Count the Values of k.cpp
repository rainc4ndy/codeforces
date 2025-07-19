#include <bits/stdc++.h>

using namespace std;

int ilog(int base, int x) {
    return (int)(log(x) / log(base));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t, l, a, b;
	cin >> t;
	vector<int> ans(t);
	bool flag = false;
	for(int i = 0; i < t; ++i) {
		cin >> a >> b >> l;
		int t1 = ilog(a, l);
		int t2 = ilog(b, l);
		for(int j = 1; j <= l; ++j) {
			flag = false;
			for(int x = 0; x <= t1; ++x) {
				for(int y = 0; y <= t2; ++y) {
					if (l == j * pow(a, x) * pow(b, y)) {
						ans[i]++;
						flag = true;
						break;
					}
				}
				if (flag)
					break;
			}
		}
	}

	for(int i = 0; i < t; ++i) {
		cout << ans[i];
		if (i != t-1)
			cout << endl;
	}

	return 0;
}

