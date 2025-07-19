#include <algorithm>
#include <bits/stdc++.h> 
#include <utility>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

int n,c,p;
struct st {
	int x, y, z;
};
void solve() {
	cin >> n;
	std::vector<st> v(n);
	for (auto i = 0; i < n; i++) {
		cin >> v[i].x >> v[i].y;
		v[i].z = i+1;
	}
	std::sort(begin(v),end(v), [&](st&a, st&b) {
		return a.y > b.y;
	});

	int k; cin >> k;
	vector<P> sz(k); //table size, index
	for (auto i = 0; i < k;i++)  {
		cin >> sz[i].x;
		sz[i].y = i+1;
	}
	std::sort(begin(sz), end(sz));

	int sum = 0;
	vector<P> ans;
	for (int i = 0; i < n; i++) {
		auto d = lower_bound(begin(sz), end(sz), make_pair(v[i].x, 0));
		if (d != end(sz)) {
			ans.emplace_back(v[i].z, d->y);
			sum += v[i].y;
			sz.erase(d);
		}
	}

	cout << ans.size() << ' ' << sum << endl;
	for (auto& it : ans) {
		cout << it.x << ' ' << it.y << endl;
	}
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ = 1;
	while(_--) solve();

	return 0;
}