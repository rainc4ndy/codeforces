#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int mod = 2e5 + 10;
typedef unsigned long long ll;
#define x first
#define y second
typedef pair<int, int> P;

ll v[mod] {};

vector<ll> e[mod] {};
int n;

//检查根节点是否可以有满足 前祖先增长需求 "x" 的值
//可见这个条件满足单调性 
//(如果可以增长到x，那么对于任意 v[i] < y <= x 的y都可以增长到)
//所以可以二分枚举出 x
bool check(ll root, ll x) {
	if (e[root].size() == 0) {
		return v[root] >= x;
	}
	for (int i = 0; i < e[root].size(); i++) {
		if (v[e[root][i]] < x) {
			if (!check(e[root][i], x+(x-v[e[root][i]]))) {
				return false;
			}
		} else {
			if (!check(e[root][i], x)) {
				return false;
			}
		}
	}	
	return true;
}

void solve() {
	cin >> n;

	ll mx = 0;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		e[i].clear();
		mx = max(v[i], mx);
	}

	ll tmp;
	for (int i = 2; i <= n; i++) {
		cin >> tmp;
		e[tmp].push_back(i);
	}

	ll l = 0,  r = 1e9;
	ll mid,ans=0;

	while(l<=r){
		mid=(l+r)>>1;
		if (check(1, mid)) {
			l = mid+1;
			ans = mid;
		} else {
			r = mid-1;
		}
	}

	cout << v[1]+ans << endl;
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