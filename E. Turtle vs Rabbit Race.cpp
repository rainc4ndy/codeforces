#include <bits/stdc++.h>
using namespace std;

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

	int t, n, q, l, u;
	cin >> t;

	vector<vector<int>> ans(t, vector<int>());
	vector<int> lens, sum; //section, begin, bonus

	for(unsigned i = 0; i < t; ++i) {
		cin >> n;

		lens.resize(n);
		sum.resize(n); //跑道长度的总和
		for(unsigned j = 0; j < n; ++j) {
			cin >> lens[j];
		}

		cin >> q;
		ans[i].resize(q);
		for(unsigned j = 0; j < q; ++j) {
			cin >> l >> u;

			//总共有多少个section，就有多少个 ***数列的项***
			//记录从l到n，各个r总的section数
			for(unsigned r = l - 1; r < n; ++r) {
				if (r == l - 1) {
					sum[r] = lens[l - 1];
					continue;
				}
				sum[r] = sum[r - 1] + lens[r];
			}

			int S = u*u - (u*u-u) / 2;
			cout << "S = " << S << endl;
			ans[i][j] = 1;
			for(unsigned r = l - 1; r < n; ++r) { //枚举r

				if (sum[r] > u) {
					break;
				}
				ans[i][j] = r + 1;

			}
		}

	}

	cout << "OUTPUT_-_________" << endl;
	for(unsigned i = 0; i < t; ++i) {

		for(unsigned j = 0; j < ans[i].size(); ++j) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
