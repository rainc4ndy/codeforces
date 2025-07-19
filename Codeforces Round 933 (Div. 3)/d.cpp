#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    int n,m,x;
    int dis[1001], dir[1001];
    char tmp;

    int p[1001]; //0: no, 1:yes: 2:proba

    vector<vector<int>> ans(t);

    for(unsigned i = 0; i < t; ++i) {
    	cin >> n >> m >> x;

	    int trg = x;

    	for(unsigned j = 0; j < m; ++j) {
    		cin >> dis[j];
    		cin >> tmp;
    		if (tmp == '?')
    			dir[j] = -1;
    		else
    			dir[j] = tmp - '0';
    	}

    	for(unsigned j = 0; j < m; ++j) {
    		if (dir[j] == 0) {
    			p[trg] = 0;
    			trg = (trg + dis[j]) % n;

    			cout << "To " << trg << endl;
    			p[trg] = 1;
    		}
    		else if (dir[j] == 1) {
    			p[trg] = 0;
    			trg = (trg - dis[j]) % n;
    			if (trg < 0)
    				trg *= -1;
    			trg = n - trg;

    			p[trg] = 1;
    			cout << "To " << trg << endl;

    		}
    		else if (dir[j] == -1) {
    			int cache = trg;


    			if (p[trg] == 1)
	    			p[trg] = 0;


    			trg = (trg - dis[j]) % n;
    			if (trg < 0)
    				trg *= -1;
    			trg = n - trg;
    			p[trg] = 2;
    			cout << "To " << trg << endl;

    			trg = cache;
    			trg = (trg + dis[j]) % n;

    			p[trg] = 2;
    			cout << "To " << trg << endl;
    		}
    	}
    	for(unsigned j = 0; j < m; ++j) {
    		if (p[j]!=0)
    			ans[i].push_back(j);
    	}
    }

    cout << "---------------------" << endl;
    for(unsigned i = 0; i < t; ++i) {
    	cout << ans[i].size() << endl;
    	for(unsigned j = 0; j < ans[i].size(); ++j) {
    		cout << ans[i][j];
    		if (j != ans[i].size() -1)
    			cout << ' ';
    	}
    	if (i != t -1)
    		cout << endl;
    }

	return 0;
}
