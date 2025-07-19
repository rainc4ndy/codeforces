#include <bits/stdc++.h> 
  
int main() {
    using namespace std;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int n, k;
	cin >> n >> k;

	int top = 4 * 60 - k;

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		top -= i * 5;
		if (top >= 0) {
			ans++;
		} else {
			break;
		}
	}
	cout << ans;

	return 0;
}