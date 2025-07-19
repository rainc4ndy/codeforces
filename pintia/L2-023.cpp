#include <bits/stdc++.h> 
using namespace std;

const int SZ = 501;

int edge[SZ][SZ], ecnt[SZ] {}, col[SZ] {};

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    memset(edge, -1, sizeof(edge));

    int v, e, k, x, y, n, cnt;
    
    cin >> v >> e >> k;
    for(unsigned i = 0; i < e; ++i) {
    	cin >> x >> y;
    	x--;
    	y--;
    	edge[x][ecnt[x]++] = y;
    }

    bool flag;
    set<int> s;
  	cin >> n;

    vector<bool> ans(n);
    for(unsigned i = 0; i < n; ++i) {
    	s.clear();

    	for(unsigned j = 0; j < v; ++j) {
    		cin >> col[j];
    		s.insert(col[j]);
    	}
    	if (s.size() != k) {
    		ans[i] = false;
    		continue;
    	}

    	cnt = 0;
    	flag = true;
    	for(unsigned j = 0; j < v; ++j) {
    		for(unsigned x = 0; x < ecnt[x]; ++x) {
    			if (col[j] == col[edge[j][x]]) {
    				flag = false;
    			}
    		}
    		if (!flag)
    			break;
    	}

    	ans[i] = flag;
    }

    for(unsigned i = 0; i < n; ++i) {
    	cout << (ans[i] ? "Yes" : "No");
    	if (i != n-1)
    		cout << endl;
    }
	return 0;
}