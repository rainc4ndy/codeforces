#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int SZ = (1e+4) + 1;

vector<int> e[SZ];

int path[SZ] {};
int ans[SZ] {};

int ans_len = 0;

int con[SZ] {}; // 有多少条边连到i
void dfs(int x, int len) {
	path[len] = x;
	if (!e[x].size()) {
		if (len >= ans_len) {
			bool f = len != ans_len;
			if (!f) {
				for (int i = 1; i <= len; i++) {
					if (path[i] < ans[i]) {
						f = true;
						break;
					} else if (path[i] > ans[i]) {
						break;
					}
				}
			}
			if (f) {
				ans_len = len;
				for (int i = 1; i <= len; i++) {
					ans[i] = path[i];
				}
			}
		}
		return;
	}

	for (int i = 0; i < e[x].size(); i++) {
		dfs(e[x][i], len + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int k, tmp;
	for (int i = 0; i < n; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> tmp;
			e[i].emplace_back(tmp);
			con[tmp]++;
		}
	}

	for (int i = 0; i < n; i++) {
		if (!con[i])
			dfs(i, 1);
	}

	cout << ans_len << endl;
	for (int i = 1; i <= ans_len; i++) {
		cout << ans[i];
		if (i != ans_len)
			cout << ' ';
	}

	return 0;
}