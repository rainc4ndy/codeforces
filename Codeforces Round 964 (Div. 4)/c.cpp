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
	ll n,s,m;
	cin >> n >> s >> m;


	ll x, y;

	vector<ll> v;
	ll last = 0;
	bool f = false;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;

		if (!f) {
			v.push_back(x - last);
		} else {
			v.push_back(x - y);
		}

		f = true;
		last = y;

		f ^= 1;

		if (i == n-1)
			v.push_back(m - y);
	}


	for (int i = 0; i < v.size(); i++) {
		if (v[i] >= s) {
			cout << "YES" << endl;
			return;
		}
	}

	cout << "NO" << endl;
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