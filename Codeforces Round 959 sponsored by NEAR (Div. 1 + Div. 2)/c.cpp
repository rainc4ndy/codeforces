#include <bits/stdc++.h> 
#include <vector>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

ll v[mod];
ll pa[mod] {};

void solve() {
	ll n, x;
	cin >> n >> x;


	for (int i =1;i<=n;i++) {
		cin >> v[i];
		if (v[i] > x) {
			pa[i] = 0;
		} else {
			pa[i] = pa[i-1]+v[i];
		}
	}

	int tot = (n*n+n)/2;

	for (int i = 1; i<=n;i++) {
		if (v[i] > x) {
			tot -= i;
		} 
		else {
			if (pa[i-1] + v[i] > x) {
				tot -= 1;
			}
		}
	}
	cout << tot << endl;
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