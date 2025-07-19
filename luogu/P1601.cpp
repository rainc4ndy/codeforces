#include <bits/stdc++.h>
using namespace std;

#define SZ 100001

int v1[SZ] {}, v2[SZ] {}, ans[SZ] {};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	string a, b;
	cin >> a >> b;

	int p1 = SZ-1, p2 = SZ-1;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	for (auto it : a) {
		v1[p1--] = it - '0';
	}
	for (auto it : b) {
		v2[p2--] = it - '0';
	}

	int carry = 0, vaild = SZ - 1;
	for (int i = SZ - 1; i >= 0; i--) {
		int sum = v1[i] + v2[i] + carry;
		carry = sum / 10;
		ans[i] = sum % 10;
		if (ans[i])
			vaild = i;
	}

	for (int i = vaild; i < SZ; i++) {
		cout << ans[i];
	}

	return 0;
}
