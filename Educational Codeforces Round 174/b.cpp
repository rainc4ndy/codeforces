#include <bits/stdc++.h> 
#include <vector>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

P dir[] = {
	{0, -1},
	{1, 0},
	{-1, 0},
	{0, 1}
};

void solve() {
	int n,m;
	cin >> n >> m;

	map<int, vector<P>> um;
	vector<vector<int>> graph(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			um[graph[i][j]].emplace_back(i, j);
		}
	}

	int cnt = um.size(), bad_set = 0;
	for (auto& it : um) {
		for (auto&yt : it.y) {
			bool mark_as_bad = false;
			for (int i = 0; i < 4; i++) {
				int x = yt.x + dir[i].x, y = yt.y + dir[i].y;
				if (x >= 0 && x < n && y >= 0 && y < m) {
					if (graph[x][y] == it.x) {
						bad_set++;
						cnt--;
						mark_as_bad = true;
						break;
					}			
				}
			}
			if (mark_as_bad)
				break;
		}
	}

	if (bad_set == 0) {
		cout << cnt-1 << endl;
	} else {	
		cout << max(0, cnt + (bad_set-1) * 2) << endl;
	}
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _;
	cin >> _;
	while(_--) solve();

	return 0;
}