#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

int n,m;
int p[mod], sz[mod];

int find(int x) {
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}

void mmm(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	p[x] = y;
	sz[y] += sz[x];
}

void solve() {
	cin >> n >> m;
	for (int i =0;i < n; i++) {
		p[i] = i; sz[i] =1;
	}
	for (int i =1;i <= m; i++) {
		int u,v;
		cin >> u >> v ;
		mmm(u,v);
	}
	int cnt = 0, mx = 0;
	for (int i =0; i < n; i++) {
		if (i == find(i)) {
			mx = max(mx, sz[i]);
			cnt++;
		}
	}
	cout << cnt << ' ' << mx;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ = 1;
	while(_--) solve();

	return 0;
}