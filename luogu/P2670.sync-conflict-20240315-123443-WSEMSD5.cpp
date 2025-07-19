#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int v[102][102] {};
	string s;
	for(unsigned i = 0; i < n; ++i) {
		cin >> s;
		for(unsigned j = 0; j < m; ++j) {
			v[i + 1][j + 1] = s[j] == '*' ? -1 : 0;
		}
	}

	for(unsigned i = 1; i < n + 1; ++i) {
		for(unsigned j = 1; j < m + 1; ++j) {
			if (v[i][j] == -1)
				continue;
			pair<int, int> vec2d[] = {
				{i + 1, j + 1},
				{i - 1, j - 1},
				{i + 1, j},
				{i, j + 1},
				{i - 1, j},
				{i, j - 1},
				{i + 1, j - 1},
				{i - 1, j + 1},
			};
			for (auto it : vec2d) {
				if (v[it.first][it.second] == -1) {
					v[i][j]++;
				}
			}ddd
		}
	}

	for(unsigned i = 1; i < n + 1; ++i) {
		for(unsigned j = 1; j < m + 1; ++j) {
			if (v[i][j] == -1)
				cout << '*';
			else
				cout << v[i][j];
		}
		cout << endl;
	}


	return 0;
}
