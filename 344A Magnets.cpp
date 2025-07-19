#include <bits/stdc++.h> 
#define mod (100001)
#define ll long long

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int n, h;
	cin >> n;
	int ans = 0;
	while (n--) {
		int t; 
		cin >> t;
		if (t != h)
			ans++;
		h = t;
	}

	cout << ans;
	return 0;
}