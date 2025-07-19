#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	cin >> n >> m;

	vector<int> v(n + 1);
	vector<int> t(m + 1, 0); //在区间内，数字出现的次数
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	int l = 1, r = 1;
	int num = 1;
	t[v[1]]=1;
	int ans = 0x3f3f3f3f;
	int ll, rr;
	while (l <= r && r <= n) {
		if (num ==  m) {
			//满足条件
			if (ans > r - l + 1) {
				//记录一次答案
				ans = r - l + 1; //ans记录最小区间长度
				ll = l; rr = r;
			}
			t[v[l]]--;
			if (t[v[l]] == 0) num--;
			l++;
		} else {
			r++;
			t[v[r]]++;
			if (t[v[r]] == 1) {
				num++;
			}		
		}
	}

	cout << ll << ' ' << rr;
	return 0;
}