#include <bits/stdc++.h> 
#include <queue>
using namespace std;

const int SZ = 401;

int dis[SZ][SZ] {};
bool vis[SZ][SZ] {};

int dir[8][2] = {
    {-2, 1},
    {-1, 2},
    {1, 2},
    {2, 1},
    {2, -1},
    {1, -2},
    {-1, -2},
    {-2, -1}
};

#define x first
#define y second

int n,m,x,y;

void bfs(int r1, int r2) {
    queue<pair<int, int>> q;

    q.push({r1,r2});
    vis[r1][r2] = true;
    pair<int,int> current;

    int p1,p2;
    while (!q.empty()) {
        current = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            p1 = current.x + dir[i][0];
            p2 = current.y + dir[i][1];

            if (p1 < 0 || p1 >= n)
                continue;
            if (p2 < 0 || p2 >= m) 
                continue;

            if (vis[p1][p2])
                continue;

            vis[p1][p2] = true;

            dis[p1][p2] = dis[current.x][current.y] + 1;
            q.push({p1, p2});
        }
    }
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    cin >> n >> m >> x >> y;

    x--;
    y--;
    bfs(x, y);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j])
                cout << dis[i][j];
            else cout << -1;
            if (j != m-1)
                cout << ' ';
        }
        if (i != n-1)
            cout << endl;
    }
	return 0;
}