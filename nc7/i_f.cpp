#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

ll m,k,h;
bool check(ll x) {
	ll hp = h;
	
	while (x > 0 && hp > 0) {

		ll born;
		ll unused;
		ll used;

		if (x >= m) {
			born = (x/m) * k;
			unused = x % m;
			used = x - unused;
		} else {
			born = 0;
			unused = 0;
			used = x;
		}


		hp -= used;
		x -= used;
		x += born;
	}
	return hp <= 0;
}

void solve() {
	cin >> m >> k >> h;

	if (k >= m) {
		cout << min(m, h) << endl;
		return;
	}
	
	ll l = m, r = h;
	ll mid, ans=0;
	while (l <= r) {

		mid = (l+r)>>1;

		if (check(mid)) {
			r = mid-1;
			ans = mid;
		} else {
			l = mid+1;
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