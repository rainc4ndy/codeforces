#include <bits/stdc++.h> 
#include <vector>
using namespace std;

const int mod = 501;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

int n,m;

int v[mod][mod], d[mod][mod];

void solve() {
	cin >> n >> m;	
	char c;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c;
			v[i][j] = c - '0';
		}
		cin.ignore();
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c;
			d[i][j] = c - '0';
		}
		cin.ignore();

	}

	for (int i = 1; i <= n; i++)  {
		for (int j = 1; j <= m; j++) {
			if (d[i][j] == 0 && v[i][j]  != 0) {
				cout << "___________________________" << endl;
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "___________________________" << endl;
	cout << "YES" << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int t;
	cin >> t; 

	while (t--)
		solve();

	return 0;
}