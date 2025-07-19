#include <bits/stdc++.h>
using namespace std;

const int SZ = 100000;
int lch[SZ] {}, rch[SZ] {}; //这里的左孩子右孩子其实指的是父和母
bool sex[SZ] {}; //F: female, t male;

void dfs(int n, int depth, vector<int> &v) {
	if (depth == 4) //减去起点
		return;

	if (lch[n] != -1) {
		v.push_back(lch[n]);
		dfs(lch[n], depth + 1, v);
	}

	if (rch[n] != -1) {
		v.push_back(rch[n]);
		dfs(rch[n], depth + 1, v);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int id; char s; int x, y;

	memset(lch, -1, sizeof(lch));
	memset(rch, -1, sizeof(rch));

	for (unsigned i = 0; i < n; ++i) {
		cin >> id >> s >> x >> y;

		sex[id] = s != 'F';
		sex[x] = true;
		sex[y] = false;
		lch[id] = x;
		rch[id] = y;
	}

	int m;
	cin >> m;
	vector<int> ans(m);
	vector<int> ancestA, ancestB;
	bool flag = false;

	for (unsigned i = 0; i < m; ++i) {
		cin >> x >> y;
		if (sex[x] == sex[y]) {
			ans[i] = 0;
			continue;
		}

		ancestA.clear();
		ancestB.clear();

		dfs(x, 0, ancestA);
		dfs(y, 0, ancestB);

		flag = true;
		for (auto it : ancestA) {
			for (auto yt : ancestB) {
				if (it == yt) {
					flag = false;
					break;
				}
			}
			if (!flag)
				break;
		}

		if (flag) {
			ans[i] = 2;
		} else {
			ans[i] = 1;
		}
	}

	for (unsigned i = 0; i < m; ++i) {
		switch (ans[i]) {
		case 0:
			cout << "Never Mind";
			break;
		case 1:
			cout << "No";
			break;
		case 2:
			cout << "Yes";
			break;
		}
		if (i !=m -1)
			cout << endl;
	}

	return 0;
}
