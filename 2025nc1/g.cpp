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
	ll n;
	cin >> n;
	vector<ll> v(n);
	for (int i = 0; i < n;i++) {
		cin >> v[i];
	}
	
	sort(begin(v), end(v));

	ll sum = 0;
	ll tot = 0;
	for (int i = 0; i < n;i++) {
		ll diff = (i+1) - v[i];
		sum += diff;
		tot += abs(diff);
	}
	if (sum != 0) {
		cout << -1 << endl;
		return;
	}
	cout << tot / 2 << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ = 1;
	while(_--) solve();

	return 0;
}