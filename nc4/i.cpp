#include <bits/stdc++.h> 
#include <vector>
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

vector<int> e[mod] {};
bool vis[mod] {};
int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int n,m;
	cin >> n >> m;

	int u,v;
	vector<int> d;
	for (int i =0; i <m;i++) {
		cin >> u >> v;
		
		e[u].push_back(v);
		e[v].push_back(u);

		if (!vis[u]) {
			d.push_back(u);
		}
		if (!vis[v]) {
			d.push_back(v);
		}
	}

	int sz =d.size();
	int l = 0, r = 0;

	int ans = 0;
	int last = 0;
	while (r < sz) {
		for (int i = l; i < r; i++) {
			for (int j = 0; j <= e[r].size(); j++) {
				//check if they're friend
			}
		}
		if (d[r] - last > 1) {
			ans += (r-l)*((r-l)+1)/2;
			l = r;
		}
		r++;
	}

	cout << ans;

	return 0;
}