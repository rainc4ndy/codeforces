#include <bits/stdc++.h> 
using namespace std;
 
const int mod = 2e5+10;
typedef long long ll;
typedef pair<int, int> P;
 
ll v[mod];
ll b[mod];
ll op[mod];
map<ll, ll> d;
set<ll> s;
 
void solve() {
	ll n;
	cin >> n;
 
	d.clear();
	s.clear();
 
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		s.insert(b[i]);
	}
 
	ll m;
	cin >> m;
	ll tmp;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		d[tmp]++;
		op[i] = tmp;
	}
 
	for (int i = 0; i < n; i++) {
		if (v[i] != b[i]) {
			if (d[b[i]] > 0) {
				d[b[i]]--;
				if (d[b[i]] == 0)
					d.erase(b[i]);
			} else {
				cout << "NO" << endl;
				return;
			}
		}
 	}

 	// Check if any subsequent operation can offset invalid operations
 	bool valid = false;
 	for (int i = 0; i < m; i++) {
 		if (d.count(op[i]) && s.count(op[i])) {
 			valid = true;
 			break;
 		}
 	}

	if (d.size() == 0 || valid) {
 		cout << "YES" << endl;
 		return;
 	}
 	
 	cout << "NO" << endl;
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
