#include <bits/stdc++.h> 
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
	map<ll, ll> s;
	ll x;
	bool ok = true;
	for (int i = 0; i < n; i++) {
		cin >> x;
		s[x]++;
	}
	if (s.size() == 2 && n % 2 == 0) {
		if ((begin(s)->y) ==(next(begin(s))->y)) {
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