#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

#define x first
#define y second

ll res = 0;
vector<ll> p, rk;

ll getp(ll v) {
	if (v == p[v]) return v;
	return p[v] = getp(p[v]);
}
ll get(ll cnt) {
	return cnt * 1ll * (cnt - 1) / 2;
}
void merge(ll u, ll v) {
	u = getp(u);
	v = getp(v);
	
	if (rk[u] < rk[v]) swap(u, v);
	
	res -= get(rk[u]);
	res -= get(rk[v]);
	
	rk[u] += rk[v];
	
	res += get(rk[u]);
	
	p[v] = u;
}

ll n, m;
struct st {
	ll x, y, z;
	st(ll i, ll j, ll k) : x(i), y(j), z(k) {}

	st() {}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	res = 0;
	p = rk = vector<ll>(n, 1);
	iota(p.begin(), p.end(), 0);

	vector<st> E;

	ll x, y, z;
	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y >> z;
		x--; y--;
		E.emplace_back(x, y, z);
	}

	sort(begin(E), end(E), [&](st & a, st & b) {
		return a.z < b.z;
	});

	vector<P> query;
	for (int i = 1; i <= m; i++) {
		cin >> x;
		query.emplace_back(x, i);
	}
	sort(begin(query), end(query));


	int edge_id = 0;
	vector<ll> ans(m + 1);
	for (int i = 0; i < m; i++) {
		ll max_q = query[i].x;
		ll query_id = query[i].y;

		while (edge_id < n - 1 && E[edge_id].z <= max_q) {
			auto& cur_edge = E[edge_id];
			merge(cur_edge.x, cur_edge.y);
			edge_id++;
		}
		ans[query_id] = res;
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i];
		if (i != m) cout << ' ';
	}
	return 0;
}