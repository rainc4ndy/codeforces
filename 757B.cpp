#include<bits/stdc++.h>
using namespace std;
int a[100000], n, m = 1;
int main() {
	cin >> n;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		for (int j = 1; j * j <= x; j++) {
			if (x % j == 0) {
				a[j]++;
				if (j * j != x)a[x / j]++;
			}
		}
	}
	for (int i = 2; i < 100000; i++)m = max(m, a[i]);
	cout << m;
	return 0;
}