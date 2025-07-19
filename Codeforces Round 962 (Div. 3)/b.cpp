#include <bits/stdc++.h> 
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

int v[1001][1001]{};
void solve() {
	int n, k;

	cin >> n >> k;
	char c;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c;
			v[i][j] = c-'0';
		}
		cin.ignore();
	}

	for (int i = 1; i <= n; i += k) {
		for (int j = 1; j <= n; j += k) {
			cout << v[i][j];
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