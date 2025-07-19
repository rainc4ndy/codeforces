#include <bits/stdc++.h> 
#include <vector>
using namespace std;

#define mod (100001)
#define ll long long
#define x first
#define y second
typedef pair<int, int> P;

vector<int> e[mod] {};
int rec[mod] {};
int n,m;

void dfs(int root, int mx) {
	if (rec[root])
		return;
	rec[root] = mx;
	for (int i = 0; i < e[root].size(); i++) {
		dfs(e[root][i], max(e[root][i], mx));
	} 
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

   	cin >> n >> m;

   	int x, y;
   	for (int i = 0; i < m; i++) {
   		cin >>x >> y;
   		e[y].push_back(x);
   	}

   	for (int i = n; i >= 1; i--) {
   		dfs(i, i);
   	}
   	for (int i = 1; i <= n; i++) {
   		cout << rec[i];
   		if (i <=n)
   			cout << ' ';
   	}
	return 0;
}