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
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	for (int i = 0; i < n; i++) 
		cin >> b[i];
	
	int ans = 0;

	vector<int> fa(2*n+1, 0), fb(2*n+1, 0);

	fa[a[0]] = 1;
	fb[b[0]] = 1;

	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i-1]) {
			cnt++;
			fa[a[i]] = max(fa[a[i]], cnt);
		} else {
			cnt = 1;
			fa[a[i]] = 1;
		}
	}

	cnt = 1;
	for (int i = 1; i < n; i++) {
		if (b[i] == b[i-1]) {
			cnt++;
			fb[b[i]] = max(fb[b[i]], cnt);
		} else {
			cnt = 1;
			fb[b[i]] = 1;
		}
	}

	// for (int i = 1; i <= 2*n; i++) {
	// 	cout << fa[i] << ' ';
	// }
	// cout << endl;
	// for (int i = 1; i <= 2*n; i++) {
	// 	cout << fb[i] << ' ';
	// }
	// cout << endl;

	for (int i = 1; i <= 2*n; i++) {
		ans = max(ans, fa[i]+fb[i]);
	}
	cout << ans << endl;
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