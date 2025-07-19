#include <algorithm>
#include <bits/stdc++.h> 
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<ll, ll> P;

ll v[mod];
P v2[mod];
bool rec[mod];
bool rec_ans[mod];

ll n,q;

bool check(ll d) {
	for (int i = 0; i < d;i++) {
		v2[i].x = v[i];
		v2[i].y = i;
		rec[i] = false;
	}
	sort(v2, v2+d);

	ll r = q; //剩下的智力值
	for (int i = 0; i < d; i++) {
		if (r <= 0)
			return false;
		cout << "v2[i].x = " << v2[i].x << endl;
		cout << "v2[i].y = " << v2[i].y << endl;
		if (v2[i].x > r) {

				//参加，智力减一
				rec[v2[i].y] = true;
				r--;
		} else {
			//参加
			rec[v2[i].y] = true;
		}
	}
	return true;
}

void solve() {
	cin >> n >> q;

	for (int i = 0 ; i < n; i++) {
		cin >> v[i];
	}

	ll l = 0, r = n;
	ll ans = 0, mid; 

	while (l <= r) {
		mid = (l+r)>>1;
		if (check(mid)) {
			l = mid+1;
			//update ans
			for (int i = 0; i < mid; i++) {
				rec_ans[i] = rec[i];
			}
		} else {
			l = mid-1;
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