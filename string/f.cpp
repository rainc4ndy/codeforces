#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

#define MAXL 111
#define DEGREE 26
#define MOD 20090717

int trieG[MAXL][MAXL];

struct Aho {
	int next[MAXL][DEGREE], nd[MAXL], fail[MAXL];
	int L, root;

	int newNode() {
		for (int i = 0; i < DEGREE; i++)
			next[L][i] = -1;
		nd[L] = 0;
		return L++;
	}

	void init() {
		L = 0;
		root = newNode();
	}

	void insert(char s[], int id) {
		int now = root;
		for (int i = 0, key, sz = strlen(s); i < sz; i++) {
			key = s[i] - 'a';
			if (next[now][key] == -1)
				next[now][key] = newNode();
			now = next[now][key];
		}
		nd[now] = (1 << id);
	}

	void build() {
		queue<int> que;
		fail[root] = root;
		for (int i = 0; i < DEGREE; i++) {
			if (next[root][i] == -1)
				next[root][i] = root;
			else {
				fail[next[root][i]] = root;
				que.push(next[root][i]);
			}
		}

		// Process all nodes in the trie
		while (!que.empty()) {
			int now = que.front();
			que.pop();

			if (nd[fail[now]])
				nd[now] |= nd[fail[now]];

			for (int i = 0; i < DEGREE; i++) {
				if (next[now][i] == -1)
					next[now][i] = next[fail[now]][i];
				else {
					fail[next[now][i]] = next[fail[now]][i];
					que.push(next[now][i]);
				}
			}
		}
	}
} actree;

int dp[26][MAXL][(1 << 10) + 1];
inline int bits(int a) {
	int ret = 0;
	while (a) {
		ret += (a & 1);
		a >>= 1;
	}
	return ret;
}

int main() {
	int n, m, k;
	char keyword[20];
	while (cin >> n >> m >> k) {
		if (n + m + k == 0) break;
		actree.init();
		for (int i = 0; i < m; i++) {
			scanf("%s", keyword);
			actree.insert(keyword, i);
		}

		actree.build();
		for (int i = 0; i <= n; i++)
			for (int j = 0; j < actree.L; j++)
				for (int st = 0; st <= (1 << m); st++)
					dp[i][j][st] = 0;

		dp[0][0][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < actree.L; j++) {
				for (int st = 0; st <= (1 << m); st++) {
					if (dp[i - 1][j][st]) {
						for (int k = 0, now; k < DEGREE; k++) {
							now = actree.next[j][k];
							dp[i][now][st | actree.nd[now]] += dp[i - 1][j][st];
							dp[i][now][st | actree.nd[now]] %= MOD;
						}
					}
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < actree.L; i++) {
			for (int j = 0; j <= (1 << m); j++) {
				if (bits(j) >= k) {
					ans = (ans + dp[n][i][j]) % MOD;
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}
