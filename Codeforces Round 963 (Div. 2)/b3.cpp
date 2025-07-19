#include <algorithm>
#include <bits/stdc++.h> 
#include <ios>
#include <iterator>
#include <vector>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

ll v[mod] {};
void solve() {
	int n;
	
	cin >> n;

	vector<ll> b;
	bool b1 = false, b2 = false;
	ll mx = -1e9;
	for (int i = 0; i <n;i++) {
		cin >> v[i];
		if (v[i]&1) {
			b1 = true;
			mx = max(mx, v[i]);
		} 
		else {
			b2 = true;
			b.push_back(v[i]);
		}
	} 

	if ((b1 && !b2) || (!b1 && b2)) {
		cout << 0 << endl;
		return;
	}

	sort(begin(b), end(b));

	ll ans = 0;
	for (int i = 0; i < b.size(); i++) {
		if (b[i] < mx) {
			ans++;
			mx += b[i];	
		} else {
			ans += 2;
			mx += b[b.size()-1]*2;	
		}
	}
	
	cout << ans << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}