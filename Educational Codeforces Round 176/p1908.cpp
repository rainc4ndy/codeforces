#include <bits/stdc++.h> 
using namespace std;

const int MAXN = 5e5+100;
typedef long long ll;

ll d[MAXN] = {0}; 
ll n;

ll lowbit(ll x) { return x & (-x); }

void add(ll p, ll x) {
	while (p < MAXN) {
		d[p] += x;
		p += lowbit(p);
	}	
}

ll query(ll p) {
	ll sum = 0;
	while (p > 0) {
		sum += d[p];
		p -= lowbit(p);
	}
	return sum;
}

void solve() {
	cin >> n;

	vector<ll> v(n), v_sorted;
	map<ll, ll> index_map; 

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		v_sorted.push_back(v[i]);
	}

	// 离散化
	sort(begin(v_sorted), end(v_sorted));
	v_sorted.erase(unique(begin(v_sorted), end(v_sorted)), end(v_sorted));

	for (int i = 0; i < (int)v_sorted.size(); i++) {
		index_map[v_sorted[i]] = i + 1;
	}

	ll ans = 0;
	for (int i = n-1; i >= 0; i--) {
		ll g = index_map[v[i]]; // 获取离散化后的索引
		ans += query(g - 1);    // 查询有多少个比 `v[i]` 小的元素
		add(g, 1);           
	}

	cout << ans << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	solve();
	return 0;
}
