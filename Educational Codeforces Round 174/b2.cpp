#include <bits/stdc++.h> 
#include <iterator>
#include <vector>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

P dir[] = {
	{0, -1},
	{1, 0},
	{-1, 0},
	{0, 1}
};

template<typename T>
bool cmax(T&a, const T& b) {
	return b > a ? a = b, 1 : 0;
}

void solve() {
	int n,m;
	cin >> n >> m;

	map<int, vector<P>> um;
	vector<vector<int>> graph(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			graph[i][j]--;
		}
	}

	vector<int> c(n*m, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cmax(c[graph[i][j]], 1);
			if (i && graph[i][j] == graph[i-1][j]) c[graph[i][j]] = 2;
			if (j && graph[i][j] == graph[i][j-1]) c[graph[i][j]] = 2;
		}
	}
	sort(begin(c), end(c));
	int ans = 0;
	for (int i = 0;i < c.size()-1;i++) ans+=c[i];

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