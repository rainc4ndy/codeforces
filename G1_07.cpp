#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

map<P, int> um;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;
    cin >> r >> c;

    int n1;
    int x, y, v;
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        cin >> x >> y;
        cin >> v;

        if (v != 0) {
            um[P(x, y)] += v;
        }
    }

    cin >> n1;
    for (int i = 0; i < n1; i++) {
        cin >> x >> y;
        cin >> v;

        if (v != 0) {
            um[P(x, y)] += v;

            if (um[P(x, y)] == 0)
                um.erase(P(x, y));
        }
    }

    int cnt = um.size();
    cout << cnt << endl;

    for (auto it = um.begin(); it != um.end(); it++) {
        cout << it->first.first << ' '
            << it->first.second << ' '
            << it->second;
        if (it != prev(um.end()))
            cout << endl;
    }
    return 0;
}
