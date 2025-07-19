#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	vector<bool> ans(k, true);

	int x, cur;
	for (int i = 0; i < k; i++) {
		cur = 0;
		stack<int> stk;
		for (int j = 0; j < n; j++) {
			cin >> x;
			if (!ans[i])
				continue;

			if (x - cur == 1) {
				cur++;
			} else {
				if (!stk.empty()) {
					if (stk.top() - cur == 1) {
						stk.pop();
						cur++;
					} else {
						if (stk.size() + 1 > m) {
							ans[i] = false;
						}
						stk.push(x);
					}
				}
				else {
					stk.push(x);
				}
			}
			while (!stk.empty()) {
				if (stk.top() - cur == 1) {
					stk.pop();
					cur++;
				} else {
					break;
				}
			}
		}
		ans[i] = cur == n;
	}


	for (int i = 0; i < k; i++) {
		cout << (ans[i] ? "YES" : "NO");
		if (i != k - 1)
			cout << endl;
	}
	return 0;
}