#include <algorithm>
#include <bits/stdc++.h> 
#include <functional>
  
int main() {
    using namespace std;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int n; //requirement
	cin >> n; 

	int m[12]; //growth per month
	for (int i = 0; i < 12; i++) {
		cin >> m[i];
	}

	sort(m, m + 12, greater<int>());

	int sum = 0;
	int ans = 0;
	for (int i = 0; i < 12; i++) {
		if (sum >= n) {
			cout << ans;	

			return 0;
		}
		sum += m[i];
		ans++;
		
	}
	if (sum >= n) {
		cout << ans;

	} else
	cout << -1;	

	return 0;
}