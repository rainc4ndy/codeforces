#include <bits/stdc++.h> 
#include <vector>
using namespace std;

vector<vector<int>> u; 
int n;

int mx = 0;
int ans = 0;
void dfs(int root, int len) {
	if (u[root].size() == 0) {
		if (len > mx) {
			mx = len;
			ans = root;
		}
	}

	for (auto it : u[root]) {
		dfs(it, len+1);
	}
} 

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	cin >> n;
	u.resize(n);

	vector<bool> v(n);

	int k, entry;
	for (int i = 0; i < n; i++) {
		cin >> k;
		u[i].resize(k);
		for (int j = 0; j < k; j++) {
			cin >> u[i][j];
			u[i][j]--;
			v[u[i][j]] = true;
		}
	}

	for (int i = 0; i < n; i++) {
		if (!v[i])
			entry = i;
	}

	dfs(entry, 0);
	cout << ans+1;

	return 0;
}