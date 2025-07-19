#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin >> t;

	vector<int> ans(t);

	int tmp, tmp2;
	for(unsigned i = 0; i < t; ++i) {
		cin >> tmp;
		for(unsigned j = 0; j < tmp; ++j) {
			cin >> tmp2;
			ans[i] += abs(tmp2);
		}
	}

	for(unsigned i = 0; i < t; ++i) {
		cout << ans[i];
		if (i!=t-1)
			cout << endl;
	}

	return 0;
}
