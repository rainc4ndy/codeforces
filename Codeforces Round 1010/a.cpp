#include <bits/stdc++.h> 
#include <vector>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	int n,m;
	cin >> n >> m;

	vector<vector<int>> v(n, vector<int>(m));

	for (int i =0; i < n; i++) {
		for (int j = 0;j <m;j++) {
			cin >> v[i][j];
		}
	}
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _;
	cin >> _;
	while(_--) solve();

	return 0;
}