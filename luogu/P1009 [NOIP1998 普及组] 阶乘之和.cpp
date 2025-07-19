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

	for (auto it : a)
		v1[p1--] = it - '0';
	for (auto it : b)
		v2[p2--] = it - '0';

	int *lesser = p1 > p2 ? v1 : v2;
	int *greater = p1 > p2 ? v2 : v1;

	int mx = max(p1, p2);
	int mi = min(p1, p2);

	int loc = 0;
	int vaild = SZ - 1; //有效位置
	int carry = 0, carry_p = 0; //乘法进位，加法进位

	//逆序数组，模拟乘法计算
	for (int i = SZ - 1; i >= mx; i--) { //用位数小的去乘大的，位数越小，那么前置0越多
		loc = i;
		for (int j = SZ - 1; j >= mi; j--) {
			ans[loc] += ((lesser[i] * greater[j]) % 10) + carry;
			carry = (lesser[i] * greater[j]) / 10;

			//检查加法进位
			ans[loc] += carry_p;
			carry_p = ans[loc] / 10;
			ans[loc] %= 10;

			if (ans[loc])
				vaild = loc;
			loc--;
		}
	}

	for (int i = vaild; i < SZ; i++)
		cout << ans[i];

	return 0;
}
