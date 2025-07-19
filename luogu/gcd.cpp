#include <bits/stdc++.h>
using namespace std;

int gcd_w(int a, int b) {
	int tmp;
	while (b != 0) {
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b; // 先除以GCD减小数值，再乘以另一个数
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    cout << gcd(max(a, b), min(a, b)) << ' ' << lcm(a, b);

	return 0;
}
