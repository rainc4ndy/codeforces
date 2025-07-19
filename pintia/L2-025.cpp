#include <bits/stdc++.h> 
using namespace std;

vector<int> u[10000];
bool blocked[10000] {};

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int n, m;
    cin >> n >> m;

    set<int> s;
    int x, y;
    for(unsigned i = 0; i < m; ++i) {
    	cin >> x >> y;
    	x--;
    	y--;
    	u[x].push_back(y);
    	u[y].push_back(x);
    }

    int k, np, city;
    cin >> k;
    vector<int> ans(k);
    for(int i = 0; i < k;i++) {
    	cin >> np;

    	memset(blocked, 0, sizeof(blocked));
   		for(int j = 0; j < np; j++) {
   			cin >> city;
   			city--;
   			
   			blocked[city] = true;
   		}

   		ans[i] = true;
   		for(int q = 0; q < n; q++) { 
   			if (blocked[q]) //从未封堵的城市出发
   				continue;

   			for (int q2 = 0; q2 < u[q].size(); q2++) {
   				if (!blocked[u[q][q2]]) {
   					ans[i] = false;
   					break;
   				}
   			}
   			if (!ans[i])
   				break;
   		}
    }

    for(int i = 0; i < k;i++) {
    	cout << (ans[i] ? "YES" : "NO");
    	if (i != k-1)
    		cout << endl;
    }


	return 0;
}
