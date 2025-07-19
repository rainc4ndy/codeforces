#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

	int v[100001] {};
	int ans[100001] {};
	int sz = 0, pre = 0, mx = 0;

	int sq = sqrt(n);
	for(unsigned i = 2; i < sq; ++i) {
		if (n % i == 0) {
			if (i - 1 == pre) {
				v[sz++] = i;
				if (sz > mx) {
					memcpy(ans, v, sizeof(int ) * sz);
					mx = sz;
				}
			} else {
				sz = 0;
			}
		} else {
			sz = 0;
		}
		pre = i;
	}

	//cout << mx << endl;
	int sum = 1;
	for(unsigned i = 0; i < mx; ++i) {
		for(unsigned j = mx - 1; j >= i; --j) {
			sum = 1;
			for(unsigned k = i; k < j; ++k) {
				sum *= ans[k];
			}
			cout << "sum = " << sum;
			if (sum == n) {
				cout << (j - i);
			}
		}
		//if (i != mx - 1)
		//	cout << '*';
	}
	//3*4*5*6*7*8 840

	return 0;
}
