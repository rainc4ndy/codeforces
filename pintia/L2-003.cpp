#include <bits/stdc++.h> 
 
using namespace std;

#define SZ (1001)

struct cake {
	double num;
	double sell;
};

bool f(cake &a ,cake  &b) {
	return a.sell > b.sell;
}

int main() {

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
	cout.precision(2);

	int n;
	double k;

	cin >> n >> k;

	cake c[SZ] {};

	int total = 0;
	for (int i = 0; i < n; i++) {
		cin >> c[i].num;
		total += c[i].num;
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i].sell;
		c[i].sell /= c[i].num;
	}

	if (total <= k) {
		double ans = 0;
		for (int i = 0; i < n; i++)
			ans += c[i].num * c[i].sell;
		cout << fixed << ans;
		return 0;
	}

	sort(c, c + n, f);

	double ans = 0;
	int stock = 0, dec = 0, ptr = 0;
	while (stock < k) {
		if (c[ptr].num > 0) {
			dec = min(c[ptr].num, k - stock);

			stock += dec;
			c[ptr].num -= dec;

			ans += dec * c[ptr].sell;
			ptr++;
		}
	}

	cout << fixed << ans;

	return 0;
}