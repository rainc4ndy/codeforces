#include <bits/stdc++.h>
using namespace std;

bool f(int n) {
	if (!n)
		return false;
	if (n % 10 == 2)
		return true;
	return f(n / 10);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, ans = 0;
    cin >> n;
    for(unsigned i = 1; i <= n; ++i) {
    	if (f(i))
    		ans++;
    }

    cout << n - ans;
	return 0;
}
