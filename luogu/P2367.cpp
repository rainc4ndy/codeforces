#include <bits/stdc++.h> 
using namespace std;


int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int n,p;
	cin >> n >> p;

	vector<int> v(n+2, 0), diff(n+2, 0);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		diff[i] = v[i] - v[i-1];
	}

	int x,y,z;

	for (int i = 0; i < p; i++) {
		cin >> x >> y >> z;

		diff[x] += z;
		diff[y+1] -= z;
	}

	int ans = 0x3f3f3f3f;

	for (int i = 1; i <= n; i++) {
		v[i] = v[i-1] + diff[i];
		ans = min(ans, v[i]);
	}

	cout << ans;
	return 0;
}