#include <bits/stdc++.h> 
using namespace std;

const int mod = 100;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

int n,m;

int v[7];

string s;
void solve() {

	for (int i = 0; i < 7; i++) {
		v[i] = 0;
	}
	cin >> n >> m;	

	char c;
	for (int i = 0; i < n; i++) {
		cin >> c;
		v[c - 'A']++;
	}

	int ans = 0;

	for (int i = 0; i < 7; i++) {
		ans += max(0, m - v[i]);
	}

	cout << ans << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}