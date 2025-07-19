#include <bits/stdc++.h> 
using namespace std;

int w,h;
char v[501][501];

int dir[4][2] = {
	{1, 0},
	{-1, 0},
	{0, 1},
	{0, -1}
};

bool dfs(int x, int y, int d, int r) {
	x += dir[d][0];
	y += dir[d][1];
	if (x < 0 || x >= w || x < 0 || y >= h) {
		if (r)
			return true;
		return false;
	} else if (v[x][y] == '*') {
		return dfs(x, y, d, r+1);
	} else {
		if (r)
			return true;
		return false;
	}
}

void dfs_del(int x, int y, int d) {
	x += dir[d][0];
	y += dir[d][1];
	if (x < 0 || x >= w || x < 0 || y >= h) {
		return;
	} 
	if (v[x][y] == '*') {
		v[x][y] = '.';
		dfs_del(x, y, d);
	}
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    cin >> w >> h;
    for (int i = 0; i < w; i++) {
    	for (int j= 0;j<h;j++) {
    		cin >> v[i][j];
    	}
    }

    bool ok = false;

    for (int i = 0; i < w; i++) {
    	for (int j= 0;j<h;j++) {
    		if (v[i][j] == '*') {
    			if (!ok) {
    				ok = 
	    			dfs(i, j, 0, 0) &&
	    			dfs(i, j, 1, 0) &&
	    			dfs(i, j, 2, 0) &&
	    			dfs(i, j, 3, 0);

	    			if (ok) {
	    				v[i][j] = '.';
		    			dfs_del(i, j, 0);
		    			dfs_del(i, j, 1);
		    			dfs_del(i, j, 2);
		    			dfs_del(i, j, 3);
	    			}
    			} else {
    				cout << "NO";
    				return 0;	
    			}

    		}
    	}
    }

    for (int i = 0; i < w; i++) {
    	for (int j= 0;j<h;j++) {
    		if (v[i][j] == '*') {
    			cout << "NO";
    			return 0;
    		}
    	}
    }
    if (ok) cout << "YES";
    else cout << "NO";

	return 0;
}