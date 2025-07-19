#include <bits/stdc++.h> 
#include <vector>
using namespace std;

const int mod = 2e6+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

ll a[mod];
void solve() {
	int n;
	cin >> n;
	n*=2;
	for (int i = 1; i <=n;i++) cin >> a[i];

	sort(a+1, a+1+n);
	ll sum = 0;
	a[n+1] = a[n];
	for (int i = 2; i < n; i++) {
		if (i <= n/2) sum += a[i];
		else sum -= a[i];
	}

	a[n] = a[n+1] + a[1] - sum;
	cout << a[n+1] << ' ';
	for (int i = 1; i<=n/2; i++) {
		if (i==1) cout << a[n-i+1] << ' ' << a[i] << ' ';
		else cout << a[i] << ' ' << a[n-i+1] << ' '; 
	}
	cout << endl;
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