#include <bits/stdc++.h> 
using namespace std;

#define mod (101)
#define ll long long
#define x first
#define y second
typedef pair<int, int> P;

char v[mod][mod] {};
int n,m;

P dir[8] = {
	{-1, -1},
	{0, 1},
	{0, -1},
	{1, 0},
	{1, 1},
	{1, -1},
	{-1, 1},
	{-1, 0}
};

int ans = 0;
void dfs(int x, int y) {
	int p1, p2;

	v[x][y] = '.';

	for (int i = 0; i < 8; i++) {
		p1 = x + dir[i].x;
		p2 = y + dir[i].y;
		if (p1 < 0 || p1 >= n)
			continue;
		if (p2 < 0 || p2 >= m) 
			continue;
		if (v[p1][p2] == '.')
			continue;

		dfs(p1, p2);
		//v[p1][p2] = 'W'; //不需要回溯
	}
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> v[i][j];
    	}
    }

    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		if (v[i][j] == 'W') {
    			ans++;
    			dfs(i, j);
    		}
    	}
    }

    cout << ans;

	return 0;
}