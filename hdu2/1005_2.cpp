#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

// 方向编码：0: DOWN, 1: RIGHT, 2: UP, 3: LEFT
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct Node {
    int x, y, dir;
    ll cost;
    Node(int _x, int _y, int _dir, ll _cost)
        : x(_x), y(_y), dir(_dir), cost(_cost) {}
};

struct Compare {
    bool operator()(const Node &a, const Node &b) const {
        return a.cost > b.cost;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> t(n, vector<ll>(m)); // 直线通过的时间
    vector<vector<ll>> d(n, vector<ll>(m)); // 转向的额外时间

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> t[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> d[i][j];
        }
    }
    
    // 三维 dist[i][j][dir] 表示到达 (i,j) 且驶入时方向为 dir 的最小花费
    vector<vector<vector<ll>>> dist(n, vector<vector<ll>>(m, vector<ll>(4, INF)));
    priority_queue<Node, vector<Node>, Compare> pq;
    
    // 初始状态：染染一开始向右驶入 (0,0)（对应第1行第1列），代价为 t[0][0]
    const int RIGHT = 1, DOWN = 0;
    dist[0][0][RIGHT] = t[0][0];
    pq.push(Node(0, 0, RIGHT, t[0][0]));
    
    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();
        // 如果当前状态不是最优的，则跳过
        if (cur.cost != dist[cur.x][cur.y][cur.dir]) continue;
        
        // 允许在当前海域内转向：从 cur.dir 转为任一其他方向，花费 d[cur.x][cur.y]
        for (int nd = 0; nd < 4; nd++) {
            if (nd == cur.dir) continue;
            ll newCost = cur.cost + d[cur.x][cur.y];
            if (newCost < dist[cur.x][cur.y][nd]) {
                dist[cur.x][cur.y][nd] = newCost;
                pq.push(Node(cur.x, cur.y, nd, newCost));
            }
        }
        
        // 前进：沿当前方向驶出到相邻海域，花费为相邻海域的 t 值
        int nx = cur.x + dx[cur.dir];
        int ny = cur.y + dy[cur.dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        ll newCost = cur.cost + t[nx][ny];
        if (newCost < dist[nx][ny][cur.dir]) {
            dist[nx][ny][cur.dir] = newCost;
            pq.push(Node(nx, ny, cur.dir, newCost));
        }
    }
    
    // 最终要求以 DOWN 方向驶出最后一个海域
    cout << dist[n - 1][m - 1][DOWN] << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}
