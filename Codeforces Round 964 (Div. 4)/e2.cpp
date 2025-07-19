#include <bits/stdc++.h> 
#include <iterator>
#include <unordered_map>
#include <vector>
using namespace std;

const int mod = 2e6+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

ll um[mod] {};
ll f(ll n) {
	if (um[n])
		return um[n];
	ll bk = n;
    ll count = 0;
    while (n > 0) {
        n /= 3;
        count++;
    }
    return um[bk] = count;
}

void solve() {

	ll l;

	cin >> l;
	vector<int> v;
	ll x;
	for (int i = 0; i < l;i++) {
		cin >>x ;
		v.push_back(x);
	}

	sort(begin(v), end(v));

	ll ans = f(v[0])*2 + f(v[1]);
	for (ll i = 2; i < v.size(); i++) {
		cout << "ans = " << ans << endl;
		ans += f(v[i]);
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