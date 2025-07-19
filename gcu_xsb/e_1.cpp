#include <bits/stdc++.h>
using namespace std;

/*
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
你可以假设除了整数 0 之外，这个整数不会以零开头。

1<=digits.length<=100
0<=digits[i]<=9
*/

const int mod = 2e5 + 10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	auto is_prime = [](int x) {
		if (x <= 1)
			return false;
		if (x == 2)
			return true;
		if (x % 2 == 0) //对偶数因子全部判断一次
			return false;
		for (int i = 3; i <= std::sqrt(x); i += 2) { //对奇数因子全部判断一次
			if (x % i == 0)
				return false;
		}
		return true;
	}

	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int _;
	cin >> _;
	while (_--) solve();

	return 0;
}