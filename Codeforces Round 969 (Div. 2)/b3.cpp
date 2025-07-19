#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SegmentTree {
private:
    vector<int> tree, lazy;
    int n;

    void build(int node, int start, int end, const vector<int>& data) {
        if (start == end) {
            tree[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid, data);
            build(2 * node + 2, mid + 1, end, data);
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    void propagate(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update_range(int l, int r, int value, int node, int start, int end) {
        propagate(node, start, end);
        if (start > r || end < l) return;
        if (start >= l && end <= r) {
            tree[node] += value;
            if (start != end) {
                lazy[2 * node + 1] += value;
                lazy[2 * node + 2] += value;
            }
            return;
        }
        int mid = (start + end) / 2;
        update_range(l, r, value, 2 * node + 1, start, mid);
        update_range(l, r, value, 2 * node + 2, mid + 1, end);
        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

    int query_max(int node, int start, int end) {
        propagate(node, start, end);
        return tree[node];
    }

public:
    SegmentTree(const vector<int>& data) {
        n = data.size();
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(0, 0, n - 1, data);
    }

    void update_range(int l, int r, int value) {
        update_range(l, r, value, 0, 0, n - 1);
    }

    int query_max() {
        return query_max(0, 0, n - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        SegmentTree segTree(a);
        vector<int> results;

        for (int i = 0; i < m; ++i) {
            char op;
            int l, r;
            cin >> op >> l >> r;
            if (op == '+') {
                segTree.update_range(l - 1, r - 1, 1);
            } else if (op == '-') {
                segTree.update_range(l - 1, r - 1, -1);
            }
            results.push_back(segTree.query_max());
        }

        for (int result : results) {
            cout << result << ' ';
        }
        cout << '\n';
    }

    return 0;
}
