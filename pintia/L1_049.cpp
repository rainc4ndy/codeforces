#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n);
	vector<int> cs(n); //每队已选座位的数量
	vector<int> ts(n, true); //teams: false为此队都坐满了，true表示还可以选
	vector<vector<int>> st(n);

	for (unsigned i = 0; i < n; ++i) {
		cin >> v[i];
	}

	int tm = 0, remain = n;
	int i = 0;

	while(remain != 0) {
	    while(!ts[tm]) { //循环选队，跳过坐满的队
			tm++;
			if (tm >= n)
				tm = 0;
		}

		if (remain == 1 && i != 0)
			i++;

		if (cs[tm] >= v[tm] * 10) {
			ts[tm] = false;
			remain--;
			continue;
		}

		st[tm].push_back(i + 1);
		cs[tm]++;

		tm++;
		if (tm >= n)
			tm = 0;

		i++;
	}

	for (unsigned i = 0; i < n; ++i) {
		cout << '#' << i + 1 << endl;
		int cc = 0;
		for (unsigned j = 0; j < st[i].size(); ++j) {
			cout << st[i][j];
			cc++;
			if (cc >= 10) {
				if (j != st[i].size() - 1) {
					cc = 0;
					cout << endl;
				}
			} else {
				cout << ' ';
			}
		}
		cout << endl;
	}

	return 0;
}
