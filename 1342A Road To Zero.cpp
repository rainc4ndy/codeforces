#include <algorithm>
#include <bits/stdc++.h>

#define mod (100001)
#define ll long long

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin >> t;

	long long a, b, x, y;

	long long ans[mod] {};

	long long mx, mi, am1, am2;
	for (int i = 0; i < t; i++) {
		am1 = 0;
		am2 = 0;

		cin >> x >> y;
		cin >> a >> b;

		mx = max(x, y);
		mi = min(x, y);

		// min step for high piority

		// dec both
		am1 += mi * b;
	 	// dec one
	 	am1 += (mx - mi) * a;

	 	/*
			11 47
			8 101
			wrong answer 4th numbers differ - expected: '464', found: '1399'
		*/

		//cout << "am1 = " << am1 << endl;
		//cout << "am2 = " << am2 << endl;

	 	// min $$$ for high piority
	 	if (a < b) {
	 		am2 = (x + y) * a;
	 		ans[i] = min(am1, am2);
	 	} else {
	 		ans[i] = am1;
	 	}
	}

	for (int i = 0; i < t; i++) {
		cout << ans[i];
		if (i != t - 1)
			cout << endl;
	}


	return 0;
}
