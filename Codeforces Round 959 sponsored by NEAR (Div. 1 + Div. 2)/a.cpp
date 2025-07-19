#include <bits/stdc++.h> 
#include <vector>
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

int v[20][20] {};

void solve() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}
	if (n == 1 && m == 1) {
		cout << -1 << endl;
		return;
	}

	for (int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << v[(i+1)%n][(j+1)%m] << ' ';
		}
		cout << endl;
	}
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int t;
	cin >> t;
	while(t--)
		solve();

	return 0;
}