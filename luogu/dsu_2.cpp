#include <bits/stdc++.h>
using namespace std;

struct dsu {
    std::vector<int> pa;

    explicit dsu(int size) : pa(size) {
        std::iota(pa.begin(), pa.end(), 0);
    }

    int find(int x) {
        return pa[x] == x ? x : (pa[x] = find(pa[x]));
    }

    void unite(int x, int y) {
        pa[find(x)] = find(y);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);




  return 0;
}
