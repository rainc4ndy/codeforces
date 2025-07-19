#include <bits/stdc++.h> 
#include <vector>
using namespace std;

#define mod (501)
#define ll long long
#define x first
#define y second
typedef pair<int, int> P;

char v[mod][mod] {};
//bool f[mod][mod] {};
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
		int mi_c = 0x3f3f3f3f, mx_c = 0, mi_r = 0x3f3f3f3f, mx_r = 0;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (v[j][k] == 'B') {
					mi_c = min(mi_c, k);
					mx_c = max(mx_c, k);

					mi_r = min(mi_r, j);
					mx_r = max(mx_r, j);
				}
			}	
		}
		if (mx_c - mi_c == m-1 && mx_r - mi_r == n-1) {
			ans[i] = true;
			continue;
		}

		mi_c = 0x3f3f3f3f, mx_c = 0, mi_r = 0x3f3f3f3f, mx_r = 0;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (v[j][k] == 'W') {
					mi_c = min(mi_c, k);
					mx_c = max(mx_c, k);

					mi_r = min(mi_r, j);
					mx_r = max(mx_r, j);
				}
			}	
		}
		if (mx_c - mi_c == m-1 && mx_r - mi_r == n-1) {
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