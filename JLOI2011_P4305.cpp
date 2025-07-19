//https://www.luogu.com.cn/problem/P4305

#include <bits/stdc++.h>
#include <vector>

using namespace std;

const int SZ = 100000;

struct hash_map {
	struct data {
		long long u;
		int v, nex;
	};

	data e[SZ << 1];
	int h[SZ], cnt;

	int hash(long long u) { return (u % SZ + SZ) % SZ; }

	int& operator[](long long u) {
		int hu = hash(u);
		for (int i = h[hu]; i; i = e[i].nex)
			if (e[i].u == u) return e[i].v;
		return e[++cnt] = (data) {u, -1, h[hu]}, h[hu] = cnt, e[cnt].v;
	}

	hash_map() {
		cnt = 0;
		memset(h, 0, sizeof(h));
	}
};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n;
	long long digit;
	cin >> t;

	std::vector<vector<int>> vv;
	vector<int> v;

	for (int i = 0; i < t; i++) {
		cin >> n;

		vv.push_back(v);
		hash_map m;

		for (int j = 0; j < n; j++) {
			cin >> digit;
			m[digit]++;
			if (m[digit] < 1) {
				vv[i].push_back(digit);
			}
		}
	}

	for (int i = 0; i < t; i++) {
		for (int j = 0; j < vv[i].size(); j++) {
			cout << vv[i][j];
			if (j != vv[i].size() - 1) 
				cout << ' ';
		}
		if (i != t -1)
			cout << endl;
	}
	return 0;
}