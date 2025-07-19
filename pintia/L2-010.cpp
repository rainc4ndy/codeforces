#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, m;

	cin >> n >> m >> k;

	int p1, p2, tmp;

	int f[101][101] {};
	for (unsigned i = 0; i < m; ++i) {
		cin >> p1 >> p2 >> tmp;
		p1--;
		p2--;
		f[p1][p2] = tmp;
		f[p2][p1] = tmp;
	}

	vector<int> ans(k);
	bool flag;
	for (unsigned i = 0; i < k; ++i) {
		cin >> p1 >> p2;
		p1--;
		p2--;
		if (f[p1][p2] == 1 && f[p2][p1] == 1) {
			ans[i] = 0;
		} else if (f[p1][p2] == 0 && f[p2][p1] == 0) {
			ans[i] = 1;
		} else if (f[p1][p2] == -1 && f[p2][p1] == -1) {
			//查询所有人和他们两个人的关系
			flag =false;
			for(unsigned j = 0; j < n; ++j) {
				if (f[p1][j] && f[p2][j]) { //如果有共同的朋友
					ans[i] = 2;
					flag = true;
					break;
				}
			}
			if (!flag)
				ans[i] = 3;
		}
	}

	for (unsigned i = 0; i < k; ++i) {
		switch (ans[i]) {
		case 0:
			cout << "No problem";
			break;
		case 1:
			cout << "OK";
			break;
		case 2:
			cout << "OK but...";
			break;
		case 3:
			cout << "No way";
			break;
		}
		if (i != k-1)
			cout << endl;
	}

	return 0;
}
