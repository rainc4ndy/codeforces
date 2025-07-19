#include <algorithm>
#include <bits/stdc++.h> 
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<ll, ll> P;

ll v[mod];
bool rec[mod];
bool rec_ans[mod];

ll n,q;

bool check(ll d) {
	ll r = 0; //当前参加了多少场比赛
	ll x = n-d; 
	ll q2 = q; //当前智力
	for (int i = 0; i < n; i++) {
		if (q2 <= 0) {
			rec[i] = false;
			continue;
		}
		if (v[i] <= q2) {
			r++;
			rec[i] = true;
		} else {
			if (x > 0) {
				x--;
				rec[i] = false;
			} else {
				r++;
				q2--;
				rec[i] = true;
			}
		}
	}
	if (r < d)
		return false;
	return true;
}

void solve() {
	cin >> n >> q;

	for (int i = 0 ; i < n; i++) {
		cin >> v[i];
	}

	ll l = 0, r = n;
	ll mid; 

	//查找可以参加多少场比赛
	while (l <= r) {
		mid = (l+r)/2;
		if (check(mid)) {
			l = mid+1;
			for (int i = 0; i < n; i++) {
				rec_ans[i] = rec[i];
			}
		} else {
			r = mid-1;
		}
	}

	for (int i = 0; i < n;i++) {
		cout << rec_ans[i];
	}
	cout << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int t;
	cin >> t;

	while (t--)
		solve();

	return 0;
}