#include <algorithm>
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
	ll n,x;
	cin >> n >> x;

	vector<ll> v;
	ll mi = 0x3f3f3f3f;
	for (ll i = 0; i < 30; i++) {
	    if (x & (1 << i)) {  
	    	v.emplace_back((1 << i));
	    	mi = min((ll)(1 << i), mi);
	    }
	}

	std::sort(begin(v), end(v));
	if (v.size() > n) {
		cout << x << ' ';
		for (int i = 0; i < n-1; ++i) {
			cout << mi << ' ';
		}
	} else {
		for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << ' ';
		}
		for (int i = v.size(); i < n; ++i) {
			cout << mi << ' ';
		}	
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