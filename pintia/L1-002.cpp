#include <bits/stdc++.h>

using namespace std;

// 已知首行的符号数量为奇数，计算总符号数
// **枚举**，直到 rf(i) >= n，则 i-2 为首行字符数，n-rf(i-2)为多余字符数
// 特别当 rf(i) = n时，i为首行字符数
int rf(int i) {
	if (i == 1)
		return 1;
	return i * 2 + rf(i - 2);
}

char c;

// bound 左右空格分别的个数
void println(int r, int bound) {
	for (int i = 0; i < r; i++) {
		//符号之后的空格不需要填充，否则会报格式错误
		if (i >= r - bound) 
			break;
		if (i < bound)
			cout << ' ';
		else 
			cout << c;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n >> c;

	int b = 1;
	int tmp = 0;
	int remain = 0;
	while ((tmp = rf(b)) < n) {
		b += 2;
	}
	if (tmp > n) {
		b -= 2;
		remain = n - rf(b);
	}

	// upper
	for (int bound = 0; b - bound * 2 >= 1; bound++) {
		println(b, bound);
		cout << endl;
	}

	// lower
	for (int bound = (b / 2) - 1; bound >= 0; bound--) {
		println(b, bound);
		cout << endl;
	}

	cout << remain << endl;

	return 0;
}