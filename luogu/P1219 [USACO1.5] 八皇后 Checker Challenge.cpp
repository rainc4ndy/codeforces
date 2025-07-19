#include <bits/stdc++.h>
using namespace std;

int n;
int pos[28] {}, fc[28] {}, l1[28] {}, l2[28] {};
int cnt = 0;

int ans = 0;

// 一行一行放`
int dfs(int cnt) {
	if (cnt >= n) {
		if (ans < 3) {
			for(unsigned i = 0; i < n; ++i) {
				cout << pos[i] + 1;
				if (i != n-1)
					cout << ' ';
			}
			cout << endl;
		}
		ans++;
		return 0;
	}

	//枚举每一列
	for(unsigned i = 0; i < n; ++i) {
		if (fc[i] || l1[i + cnt] || l2[cnt+n-i])
			continue;

		pos[cnt] = i;
		fc[i] = l1[i + cnt] = l2[cnt+n-i] = true;
		dfs(cnt+1);
		fc[i] = l1[i + cnt] = l2[cnt+n-i] = false;
	}
	return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n;

	dfs(0);
	cout << ans;
	return 0;
}
