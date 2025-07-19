#include <bits/stdc++.h>
#include <vector>

using namespace std;



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n, m;
	cin >> t;

	vector<int> ans(t);

	for (int i = 0; i < t; i++) {
		cin >> n >> m; //heigh, width

		int br = m / 2;
		ans[i] = (br * n);
		//int sta = h -v;
	}

	for (int i = 0; i < t; i++) {
		cout << ans[i];
		if (i != t - 1)
			cout << endl;
	}

	return 0;
}