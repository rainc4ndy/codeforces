#include <bits/stdc++.h> 
#include <iterator>
#include <random>
#include <vector>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

class dsu {
public:
	vector<int> pa;
	dsu(int sz) {
		pa.resize(sz);
		iota(begin(pa),end(pa),0);
	}
	int find(int x) {
		return x == pa[x] ? x : pa[x] = find(pa[x]);
	}
	void unite(int x, int y) {
		pa[find(x)] = find(y);
	}
};

void solve() {
	int n,m;
	cin >> n >> m;
	if (n != m) {
		cout << "NO";
	} else {
		dsu d(n+1);
		for (int i =0; i < m; i++) {
			int x,y;
			cin >> x >> y;
			d.unite(x, y);
		}
		for (int i = 2; i <= n; i++) {
			if (d.find(i) != d.find(i-1)) {
				cout << "NO" << endl;
				return;
			}

		}
		cout << "FHTAGN!";
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