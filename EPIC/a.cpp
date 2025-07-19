#include <bits/stdc++.h> 
using namespace std;

const int mod = 1e4+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

int dir[8][2]={1,0,-1,0,0,-1,0,1,1,1,1,-1,-1,1,-1,-1};

int v[mod][mod];

void solve() {
    int n,m,k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            v[i][j] = 0;
        }
    }

    int ans = 0;
    int p1,p2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool f = false;
            for (int z = 0; z < 8; z++) {
                p1 = i + dir[z][0];
                p2 = i + dir[z][1];
                if (p1 < i || p1 >=n || p2 < j || p2 >= m)
                    continue;

                if(v[p1][p2] == v[i][j]) {
                    v[p1][p2] = ++ans;
                    f = true;
                    break;
                }
            }
            if (!f) {
                v[i][j] = ++ans;
            }
        }
    }


    cout << ans << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int _;
    cin >> _;
    while(_--) solve();

    return 0;
}