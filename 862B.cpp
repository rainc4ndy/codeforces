#include <bits/stdc++.h> 
#include <vector>
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

vector<ll> e[mod];
bool col[mod];
bool vis[mod] {};
ll n; 
ll a,b;

void paint(int root, bool mode) {
	vis[root] = true;
	col[root] = mode;
	if (mode)
		b++;
	else a++;

	for (int i = 0; i < e[root].size(); i++) {
		if (vis[e[root][i]])
			continue;
		paint(e[root][i], mode ^ 1);
	}
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	cin >> n;

	ll x, y;
	for (int i = 1;i <= n-1; i++) {
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}

	paint(1, 0);

	ll ans = 0;
	for (int i = 1; i <= n;i++) {
		if (col[i]) {
			ans += a-e[i].size();
		} else ans += b-e[i].size();
	}
	cout << ans / 2;

	return 0;
}