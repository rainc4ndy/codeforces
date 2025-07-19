#include <bits/stdc++.h>
using namespace std;
#define     MAXN    101
#define     INF     99999999
#define     debug   printf("!\n")
struct Edge { int u, v; } edge[3001];
vector<int> vertex[MAXN];
int vis[MAXN], sum[MAXN], cnt[MAXN][MAXN];        //cnt[u][v]表u--v的边有多少条，用来处理重边
bool used[MAXN][MAXN][MAXN];                        //used[x][u][v]x的最短路树是否用到了边u--v
int n, m;
void init();
void dijkstra(int s, int when, int flag);
int main() {
	int when = 0;
	int u, v;
	while (scanf("%d%d", &n, &m) != EOF) {
		init();
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &u, &v);
			vertex[u].push_back(v);
			vertex[v].push_back(u);
			edge[i].u = u, edge[i].v = v;
			cnt[u][v]++, cnt[v][u]++;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			dijkstra(i, ++when, 1);
			ans += sum[i];
		}
		for (int i = 0; i < m; i++) {
			int tmp = ans;
			int u = edge[i].u, v = edge[i].v;
			for (int j = 1; j <= n; j++) if (used[j][u][v] && cnt[u][v] == 1) {
					int tmp = sum[j];
					sum[j] = 0;
					cnt[u][v]--, cnt[v][u]--;
					dijkstra(j, ++when, 2);
					cnt[u][v]++, cnt[v][u]++;
					ans = ans - tmp + sum[j];  
					sum[j] = tmp;
					int k ;
					for (k = 1; k <= n; k++) if (vis[k] != when) break;
					if (k <= n) {
						ans = INF;
						break;
					}
				}
			ans == INF ? printf("INF\n") : printf("%d\n", ans);
			ans = tmp;
		}
		for (int i = 0; i < m; i++) cnt[edge[i].u][edge[i].v] = cnt[edge[i].v][edge[i].u] = 0; 
	}
	return 0;
}
void dijkstra(int s, int when, int flag) {
	int floors = 1;
	int cur = 0;
	deque<int> Q[2];
	Q[cur].push_back(s);
	vis[s] = when;
	do {
		while (!Q[cur].empty()) {
			int u = Q[cur].front();
			Q[cur].pop_front();
			for (int Size = vertex[u].size(), i = 0; i < Size; i++) {
				int v = vertex[u][i];
				if (vis[v] != when && cnt[u][v] > 0) {
					if (flag == 1) used[s][u][v] = used[s][v][u] = true;
					vis[v] = when;
					sum[s] += floors;
					Q[1 - cur].push_back(v);
				}
			}
		}
		floors++;
		cur = 1 - cur;
	} while (!Q[cur].empty());
}
void init() {
	memset(sum, 0, sizeof(sum));
	memset(used, false, sizeof(used));
	for (int i = 1; i <= n; i++) vertex[i].clear();
}