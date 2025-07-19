#include <bits/stdc++.h> 
#include <queue>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

struct st {
	int x,y,z;
	st(int X, int Y, int Z) : x(X), y(Y), z(Z) {}
};

char v[1024][1024];
vector<P> dir = {
	{ 0, 1},
	{ 1, 0},
	{ 0, -1},
	{ -1, 0}
};
bool vis[1024][1024] {};
int n,m;
int s1,s2,e1,e2;
int ans =0x3f3f3f3f;

void bfs() {
	queue<st> q;

	q.emplace(s1,s2,0);
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		vis[cur.x][cur.y] = true;
		if (cur.x == e1 && cur.y == e2) {
			ans = min(ans,cur.z);
			continue;
		}
		for (auto p : dir) {
			auto a = p.x + cur.x, b =  p.y + cur.y;
			if (0 > a ||a >= n||0>b||b >=m) {
				continue;
			}
			if (v[a][b] == '*' || vis[a][b])
				continue;

			if (v[cur.x][cur.y] == '|') {
				if (cur.z % 2 == 0 && (cur.x == a || cur.y == b)) {
					q.emplace(a,b,cur.z);
				}
			}
			else if (v[cur.x][cur.y] == '-') {
				if (cur.z % 2 != 0 && (cur.x == a || cur.y == b)) {
					q.emplace(a,b,cur.z);
				}
			} else {
				q.emplace(a,b,cur.z + 1);
			}
		}
	}
}

void solve() {
	cin >> n >> m;
	for (int i=0;i<n;i++) {
		for (int j =0;j<m;j++) {
			cin >> v[i][j];
			if (v[i][j] == 'S') s1=i,s2=j;
			else if (v[i][j] == 'T') e1=i,e2=j;
		}
	}
	bfs();
	cout << ans;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ = 1;
	while(_--) solve();

	return 0;
}