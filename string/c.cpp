#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

constexpr int N = 510050;
constexpr int MAX_TRIE = 5000050;

using ll = long long;

int n, tot = 1;
ll ans = 0;

int bo[N];                        // bo[u]: string ID if node u is the end of a string
int fa[N];                        // Union-Find parent
int son[N];                       // Subtree size
int id[N];                        // dfs order
int trie[MAX_TRIE][26];          // Trie array
vector<int> tree[N];             // DAG/tree edges
int num = 0;

int find(int x) {
    return (fa[x] == x ? x : fa[x] = find(fa[x]));
}

void insert(const string &s, int id) {
    int node = 1;
    for (int i = static_cast<int>(s.size()) - 1; i >= 0; --i) {
        int c = s[i] - 'a';
        if (!trie[node][c]) trie[node][c] = ++tot;
        node = trie[node][c];
    }
    bo[node] = id;
}

void build(int x) {
    for (int i = 0; i < 26; ++i) {
        int v = trie[x][i];
        if (!v) continue;
        if (!bo[v]) {
            fa[v] = find(x);
        } else {
            tree[bo[find(x)]].push_back(bo[v]);
        }
        build(v);
    }
}

void computeSubtreeSize(int x) {
    son[x] = 1;
    for (int v : tree[x]) {
        computeSubtreeSize(v);
        son[x] += son[v];
    }
    sort(tree[x].begin(), tree[x].end(), [](int a, int b) {
        return son[a] < son[b];
    });
}

void dfs(int x) {
    id[x] = num++;
    for (int v : tree[x]) {
        ans += num - id[x];
        dfs(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        insert(s, i);
    }

    for (int i = 1; i <= tot; ++i) fa[i] = i;

    build(1);
    computeSubtreeSize(0);
    dfs(0);

    cout << ans << '\n';
    return 0;
}
