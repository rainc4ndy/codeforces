#include <bits/stdc++.h> 
using namespace std;

#define mod (200005)
#define ll long long
#define x first
#define y second
typedef pair<int, int> P;

ll n, m,s;
ll w[mod] {}, v[mod] {};

P r[mod] {};

ll pa[mod] {}, pav[mod] {}; 

ll gety(ll x) {
	memset(pa, 0, sizeof(pa));
	memset(pav, 0, sizeof(pav));

	ll res = 0;
	for (int i = 1; i <= n; i++) {
		if (w[i] >= x)  {
			pa[i] = pa[i-1] + 1; 
			pav[i] = pav[i-1] + v[i];
		}
		else {
			pa[i] = pa[i-1];
			pav[i] = pav[i-1];
		}
	}

	for (int i = 1; i <= m; i++) {
		res += (pa[r[i].y] - pa[r[i].x-1]) * (pav[r[i].y] - pav[r[i].x-1]);
		//cout << "(pa[r[i].y] - pa[r[i].x-1]) = " << (pa[r[i].y] - pa[r[i].x-1]) << endl;
		//cout << "(pav[r[i].y] - pav[r[i].x-1]) = " << (pav[r[i].y] - pav[r[i].x-1]) << endl;
	}

	return res;
}

bool f(ll y) {
	if (s > y)
		return true; //y要变大
	else return false;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	cin >> n >> m >> s;

	ll mi = 0x3f3f3f3f3f3f3f3f, mx = 0;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
		mi = min(mi, w[i]);
		mx = max(mx, w[i]);
	}
	for (int i = 1; i <= m; i++) {
		cin >> r[i].x >> r[i].y;
	}

	ll l = mi, r = mx;
	ll mid = 0, ans = 0x3f3f3f3f3f3f3f3f;
	while (l <= r) {
		mid = (l+r)>>1;

		ll y = gety(mid);
		if (f(y)) {
			r = mid-1; //缩小w的范围，相当于扩大y
		} else {
			l = mid+1; //扩大w的范围，相当于缩小y
		}
		if (abs(s - y) < ans) 
			ans = abs(s - y);
	}

	cout << ans;
 
	return 0;
}