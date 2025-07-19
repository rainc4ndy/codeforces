#include <bits/stdc++.h> 
using namespace std;

#define mod (100001)
#define ll long long

ll v[mod] {};
ll sum[mod] {};
int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int t;
	cin >> t;
	int n, k;
	ll mx = 0, r;
	while (t--) {
		cin >> n >> k;

		r = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			if (i)
				sum[i] = sum[i-1] + v[i];
			else 
				sum[i] = v[i];
			mx = max(sum[i], mx);
		}

		while (k--) {
			
		}
	}

	return 0;
}