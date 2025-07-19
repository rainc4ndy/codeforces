#include <bits/stdc++.h> 

using namespace std;

const int INF = 0x3f3f3f3f;

struct node {
    int id;
    int length;
    node *path;

    node(int x): id(x), length(INF), path(nullptr) {}
};

typedef pair<int, int> iPair;

void dijkstra(int source, vector<node> &graph, vector<vector<pair<int, int>>> &edges) {
    priority_queue<iPair, vector<iPair>> pq;

    pq.push(make_pair(0, source)); //add source

    while (!pq.empty()) {
        node u = graph[pq.top().second];
        
        pq.pop();

        for (pair<int, int> e : edges[u.id]) {
            node n = graph[e.first];
            int length = e.second;

            //如果这条路的距离在邻接表里面短一些
            if (graph[u.id].length + length < graph[n.id].length) {
                graph[n.id].length = graph[u.id].length + length;
                graph[n.id].path = &graph[pq.top().second]; //设置前驱节点

                pq.push(make_pair(length, n.id));
            }
        }
    }
}

int main() {
    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int n, m; //city, road
    int s, d; //start, end.

    cin >> n >> m >>  s >> d;

    vector<int> v(n); //team num
    vector<node> graph;
    vector<vector<pair<int, int>>> edges(n);

    for (int i = 0; i < n; i++)  {
        cin >> v[i];
        graph.push_back(node(i));
        if (i == s) {
            // 起始点到自己的最短距离是0
            graph.back().length = 0;
        }
    }

    int c1, c2, length;
    for (int i = 0; i < m; i++) {
        cin >> c1 >> c2 >> length;
        edges[c1].push_back(make_pair(c2, length));
        edges[c2].push_back(make_pair(c1, length));
    }

    dijkstra(s, graph, edges);

    int teams = 0;
    int ans[501];
    int count = 0;
    node *ptr = &graph[d];

    while (ptr != nullptr) {
        ans[count++] = ptr->id;
        teams += v[ptr->id];
        ptr = ptr->path;
    }   

    //第一行输出 最短 路径的条数和能够召集的 最多 的救援队数量。
    cout << count - 1 << ' ' << teams << endl;

    //第二行输出从S到D的路径中经过的城市编号
    for (int i = count - 1; i >= 0; i--) {
        cout << ans[i];
        if (i != 0)
            cout << ' ';
    }
    
    return 0;
}