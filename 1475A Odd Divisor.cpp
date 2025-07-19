#include <bits/stdc++.h> 
  
#define mod (100001)
#define ll long long

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int t;
	cin >> t;

	bool ans[mod] {};

	int n; 
	int c = 0;
	for (int i = 0; i < t; i++) {
		cin >> n;
		if (n < 2)
			continue;

		for (int k = 1; k <= i; k++) {
			if (i % k == 0 && k % 2 != 0) {
				c++;
				if (c >= 2) {
					ans[i] = true;
					break;
				}
			}
		}
	}

	for (int i = 0; i < t; i++) {
		cout << (ans[i] ? "YES" : "NO");
		if (i != t - 1)
			cout << endl;
	}


	return 0;
}