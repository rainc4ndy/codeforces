#include <bits/stdc++.h> 
using namespace std;
 
const int mod = 2e5+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;
 
ll v[mod];
ll b[mod];
ll op[mod], op2[mod];
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
		d[b[i]]++;
	}
 
	ll m;
	cin >> m;
	ll tmp;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		op[i] = tmp;
	}

	bool pending = false;
	for (int j = 0; j < m; j++) {
		if (d[op[j]] > 0) {
			d[op[j]]--;
			pending = false;
		} else {
			pending = true;
		}
	}

	if (pending)
		cout << "NO" << endl;
	else
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