#include <bits/stdc++.h> 
#include <vector>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<ll, ll> P;

void solve() {
	ll n; cin >> n;

	vector<ll> v(n);
	for (int i =0; i < n; i++) {
		cin >> v[i];
	}

	int mx = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = i; j < n; j++) {
			if (v[j] <= v[i]) {
				cnt++;
			}
		}
		mx = max(mx, cnt);
	}
	cout << n - mx << endl;
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