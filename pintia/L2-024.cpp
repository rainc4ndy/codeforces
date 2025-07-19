#include <bits/stdc++.h>

using namespace std;
const int SZ = 100001;

int pa[SZ] {};
int find(int b) {
    return b == pa[b] ? b : (pa[b] = find(pa[b]));
}

void merge(int a, int b) {
    pa[find(a)] = find(b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    iota(pa, pa+SZ, 0);

    set<int> u;
    int _, k, n, pre = -1;
    cin >> _;
    while (_--) {
        cin >> k;
        pre = -1;
        for(int i = 0; i < k; i++ ) {
            cin >>n;
            u.insert(n);

            if (pre != -1)
               merge(n, pre);
            pre = n;
        }
    }

    int q, a, b;
    cin >> q;
    vector<char> ans(q);

    for(int i =0; i < q; i++) {
        cin >> a >> b;
        ans[i] = (find(a) == find(b)) ? 'Y' : 'N';
    }

    int r, sum = 0;
    set<int> u2;
    for (auto it :u) {
        r = find(it);
        if (r == it) {
            sum++;
        }
    }

    cout << u.size() << ' ' << sum << endl;

    for (int i = 0; i < q; i++) {
        cout << ans[i];
        if (i != q-1)
            cout << endl;
    }

    return 0;
}

