#include <bits/stdc++.h> 
#include <vector>
using namespace std;

/*int buy(int n, int a, int b) {
	if (n == 1) {
		return a;
	}
	if (n == 2) {
		return b;
	}
	return buy(n, a, b) + buy(n-1, a, b);
}*/

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int t;
	cin >> t;
	int n, a, b;
	vector<int> ans(t);
	for (int i = 0; i < t; i++) {
		cin >> n >> a >> b;

		if (a*2 < b) {
			ans[i] = n*a;
		} else {
			if (n % 2 == 0) {
				ans[i] = n/2*b;
			} else {
				ans[i] = (n-1)/2*b;
				ans[i] += a;
			}
		}
	}

	for (int i = 0; i < t; i++) {
		cout << ans[i];
		if (i != t-1)
			cout << endl;
	}

	return 0;
}