#include <bits/stdc++.h> 
#include <vector>
using namespace std;

#define mod (501)
#define ll long long
#define x first
#define y second
typedef pair<int, int> P;

char v[mod][mod] {};
int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int t;
	cin >> t;
	int n,m;
	vector<bool> ans(t, false);
	for (int i = 0; i < t; i++) {
		cin >> n >> m;

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> v[j][k];
			}	
		}	

		if (v[0][0] == v[n-1][m-1]) {
			ans[i] = true;
			continue;
		}
		//memset(f, 0, sizeof(f));
		int cnt = 0;
		int mi = 0x3f3f3f3f, mx = 0;
		for (int j = 0; j < n; j++) {
			bool ok = false;
			for (int k = 0; k < m; k++) {
				if (v[j][k] == 'B') {
					if (!ok)
						cnt++;
					ok = true;
					mi = min(mi, k);
					mx = max(mx, k);
				}
			}	
		}
		if (cnt == n && mx - mi == m-1) {
			ans[i] = true;
			continue;
		}

		cnt = 0;
		mi = 0x3f3f3f3f, mx = 0;
		for (int j = 0; j < n; j++) {
			bool ok = false;
			for (int k = 0; k < m; k++) {
				if (v[j][k] == 'W') {
					if (!ok)
						cnt++;
					ok = true;
					mi = min(mi, k);
					mx = max(mx, k);
				}
			}	
		}
		if (cnt == n && mx - mi == m-1) {
			ans[i] = true;
			continue;
		}
	}

	for (int i = 0; i < t; i++) {
		if (ans[i])
			cout << "YES";
		else 
			cout << "NO";
		if (i != t-1)
			cout << endl;
	}

	return 0;
}