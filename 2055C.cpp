#include <bits/stdc++.h> 
#include <cstring>
#include <vector>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;
const int MAXN = 1024;

ll v[MAXN][MAXN];
bool vis[MAXN][MAXN] {};
int n,m;

bool is_ok(int x, int y) {
	if (x < 0 || x > )
}

void solve() {
	cin >> n >> m;
	string s;
	cin >> s;

	memset(vis, 0, sizeof(vis));
	int row = 0, col = 0;
	vis[row][col] = true;
	for (auto&it :s) {
		if (it == 'D') row--;
		else col++;
		vis[row][col] = true;
	}

	row = 0, col = 0;
	vis[row][col] = true;
	for (auto&it :s) {
		if (it == 'D') row--;
		else col++;
		if ()
	}

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