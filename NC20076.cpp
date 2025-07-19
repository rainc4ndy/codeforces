#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int n, m, cnt, color[maxn], curcolor[maxn], head[maxn], sum[maxn], ans;
struct node { int u, v, next; } E[maxn * 4];

void add(int u, int v) {
    E[cnt].u = u;
    E[cnt].v = v;
    E[cnt].next = head[u];
    head[u] = cnt++;
}

void init() {
    memset(head, -1, sizeof(head));
    cnt = 0;
}

int main() {
    init();
    scanf("%d%d", &n, &m);

    // 读取布丁的颜色并初始化
    for (int i = 1; i <= n; i++) {
        scanf("%d", &color[i]);
        if (color[i] != color[i - 1]) ans++;
        sum[color[i]]++;
        curcolor[color[i]] = color[i];
        add(color[i], i);
    }

    // 处理每一个操作
    for (int i = 1; i <= m; i++) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            // 颜色转换操作
            int x, y;
            scanf("%d%d", &x, &y);

            if (x == y) continue;

            // 选择节点较少的颜色段进行合并
            if (sum[curcolor[x]] > sum[curcolor[y]]) swap(curcolor[x], curcolor[y]);
            int fx = curcolor[x], fy = curcolor[y];

            // 如果颜色段fx已经没有布丁，则跳过该操作
            if (sum[fx] == 0) continue;

            // 遍历颜色段fx的链表，更新颜色和ans
            for (int i = head[fx]; i + 1; i = E[i].next) {
                int v = E[i].v;
                if (color[v + 1] == fy) ans--;
                if (color[v - 1] == fy) ans--;
            }

            // 将颜色段fx的所有节点改为颜色fy，并更新链表
            for (int i = head[fx]; i + 1; i = E[i].next) {
                color[E[i].v] = fy;
                add(fy, E[i].v);
            }

            // 清空颜色段fx的链表，更新sum和ans
            head[fx] = -1;
            sum[fy] += sum[fx];
            sum[fx] = 0;

        } else {
            // 查询当前颜色段的数量
            printf("%d\n", ans);
        }
    }

    return 0;
}
