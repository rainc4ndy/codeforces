#include <bits/stdc++.h> 
#include <climits>
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
	vector<vector<ll>> a(n, vector<ll>());

	ll all_mi = LONG_LONG_MAX;
	for (int i = 0; i < n; i++) {
		ll x; cin >> x;
		for (int j = 0; j < x; j++) {
			ll y; cin >> y;
			a[i].emplace_back(y);
			all_mi = min(all_mi, y);
		}
	}

	for (int i = 0; i < n; i++) {
		sort(begin(a[i]), end(a[i]));
	}

	ll mi = LONG_LONG_MAX, id = -1; 
	for (int i = 0; i < n; i++) {
		if (a[i][1] < mi) {
			id = i;
			mi = a[i][1];
		}
	}

	ll ans = all_mi;
	for (int i = 0; i < n; i++) {
		//cout << "ans = " << ans <<endl;
		if (i != id) {
			ans += a[i].size() > 1 ? a[i][1] : a[i][0];
		}
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