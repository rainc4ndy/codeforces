#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, ans = 0; //greatest, least
	cin >> a >> b;

	for(int i = a; i <= b; ++i) {
		int k = a * b / i;
		if (gcd(k, i) == a && k / gcd(k, i) * i == b)
			ans++;
	}
	cout << ans;
	return 0;
}
