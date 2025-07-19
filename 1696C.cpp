#include <bits/stdc++.h> 
#include <vector>
using namespace std;

const int mod = 5e4+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

vector<ll> v(mod), d(mod); 

void solve() {
	ll n,m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	ll k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> d[i];
	}

	for (int i = 0; i < k; i++) {
		if (v[i] != d[i]) {
			if (v[i] < d[i]) {
				int need = d[i] / m;
				
			}
		}
	}

	cout << "Yes" << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int t;
    cin >> t;
    while (t--) solve();

	return 0;
}