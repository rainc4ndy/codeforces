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
	ll n;
	cin >> n;
	vector<ll> v(n), pa(n + 1, 0), su(n + 1, 0);

	set<ll> s1,s2;	
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	pa[0] = 1;
	s1.insert(v[0]);
	for (int i = 1; i < n; i++) {
		if (s1.count(v[i])) {
			pa[i] = pa[i-1];
		} else {
			s1.insert(v[i]);
			pa[i] = pa[i-1] + 1;
		}
	}

	su[n-1] = 1;
	s2.insert(v[n-1]);
	for (int i = n-2; i >= 0; i--) {
		if (s2.count(v[i])) {
			su[i] = su[i+1];
		} else {
			s2.insert(v[i]);
			su[i] = su[i+1] + 1;
		}
	}

	// for (int i = 0; i < n; i++) {
	// 	cout << pa[i] << ' ';
	// }
	// cout << endl;
	// for (int i = 0; i < n; i++) {
	// 	cout << su[i] << ' ';
	// }
	// cout << endl;	 

	ll ans = 0;
	for (int i = 0; i < n;i++) {
		ll res = pa[i] + su[i+1];
		ans = max(res,ans);
	}
	cout << ans;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ = 1;
	while(_--) solve();

	return 0;
}