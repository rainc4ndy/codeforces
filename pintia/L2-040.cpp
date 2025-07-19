#include <bits/stdc++.h> 
#include <vector>
using namespace std;

const int SZ = 1e5+1;

vector<int> u[SZ];
int save[101];
int cur = 1;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int n, m;
	cin >> n >> m;

	int k;

	for (int i = 1; i <= n; i++) {
		cin >> k;
		u[i].resize(k+1);
		for (int j = 1; j <= k; j++) {
			cin >> u[i][j];
		}
	}

	vector<int> ans;

	int x, y;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		if (x == 0) {
			cur = u[cur][y];
		} else if (x == 1) {
			save[y] = cur;
			ans.push_back(cur);
		} else {	
			cur = save[y];
		}
	}

	for (auto it : ans) {
			
		cout << it;
		cout << endl;
	}

	cout << cur;

	return 0;
}