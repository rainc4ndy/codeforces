#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50010;

int n;
int ans;

int H[MAXN];
int cnt[MAXN]; //cnt[i] 把屏障放在i的前面，可以减少的力量数量
int ca = 0;

void solve(int caseNum) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> H[i];
		cnt[i] = 0;
	}

	stack<int> stk;
	for (int i = 1; i <= n; i++) {
		int r = 0;
		while (!stk.empty() && H[stk.top()] < H[i]) {
			cnt[stk.top()] += stk.size();
			stk.pop();
		}
		if (!stk.empty())
			cnt[stk.top()] += stk.size();
		stk.push(i);
	}

	int mxi = 0, mx = 0;
	for (int i = 1; i <= n; i++) {
		if (mx < cnt[i]) {
			mx = cnt[i];
			mxi = i;
		}
	}

	cout << "Case #" << ++ca << ": " << mxi+1 << " " << mx << "\n";
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		solve(i);
	}

	return 0;
}
