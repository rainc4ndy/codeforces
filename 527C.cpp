#include <bits/stdc++.h> 
#include <iterator>
#include <set>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	ll w,h,n;
	cin >> w >> h >> n;
	set<ll> sy, sx; // 用来存切割点，搜索树
	sy.insert(0), sy.insert(h);
	sx.insert(0), sx.insert(w);

	multiset<ll> ly, lx;
	ly.insert(h);
	lx.insert(w);

	for (int i = 0; i < n; i++) {
		char h;ll x;
		cin >> h >> x;

		if (h == 'H') {
			sy.insert(x);
			auto p = sy.find(x);
			auto u = next(p), d = prev(p);

			ly.erase(ly.find(*u-*d));
			ly.insert(*u-*p); //*u-*p 和 *p-*d 可能重合
			ly.insert(*p-*d);
		} else {
			sx.insert(x);
			auto p = sx.find(x);
			auto u = next(p), d = prev(p);
			
			lx.erase(lx.find(*u-*d));
			lx.insert(*u-*p);
			lx.insert(*p-*d);
		}
		cout << (*prev(ly.end())) * (*prev(lx.end())) << endl;
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