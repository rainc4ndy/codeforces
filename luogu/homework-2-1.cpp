#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

	const int n = 5;
	int a[n] {};

	cout << "write " << n << " nums to find mx:";

	for(unsigned i = 0; i < n; ++i) {
		cin >> a[i];
	}

	// O(n) 双向搜索
	int mx = INT_MIN, mxl = INT_MIN;
	for(unsigned i = 0; i < n / 2; ++i) {
		mx = max(mx, a[i]);
		mx = max(mx, a[n-i-1]);
	}
	for(unsigned i = 0; i < n / 2; ++i) {
		if (mx != a[i])
			mxl = max(mxl, a[i]);
		if (mx != a[n-i-1])
			mxl = max(mxl, a[n-i-1]);
	}

	cout << "greatest: " << mx << endl;
	cout << "less greater: ";
	if (mxl == INT_MIN) {
		cout << "does not exist!";
	} else {
		cout << mxl;
	}
	cout << endl;

	return 0;
}
