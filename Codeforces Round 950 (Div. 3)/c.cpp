#include <bits/stdc++.h> 
using namespace std;
 
const int mod = 2e5+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;
 
ll v[mod];
ll b[mod];
map<ll, ll> d;
map<ll, ll> d2;
set<ll> s;
ll op[mod];

void solve() {
	ll n;
	cin >> n;
 
	d.clear();
	d2.clear();
	s.clear();
 
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		s.insert(b[i]);
		d2[b[i]]++;
	}
 
	ll m;
	cin >> m;
	ll tmp;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		d[tmp]++;
		op[i] = tmp;
	}

	bool pending = false;
	for (int j = 0; j < m; j++) {
		if (d2[op[j]] > 0) {
			pending = false;
		} else {
			pending = true;
		}
	}
	if (pending) {
		cout << "NO" << endl;
		return;
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
 
/*	if (d.size() == 0) {
 		cout << "YES" << endl;
 		return;
 	}
 
 	//greedy
 	for (auto it: d) {
 		if (s.count(it.x)) {
 			cout << "YES" << endl;
 			return;
 		}
 	}
 	*/
 	cout << "YES" << endl;
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