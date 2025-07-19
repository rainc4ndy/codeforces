#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    vector<bool> d(n);
    d[0] = true;
    //-: to left, +: to right

    for(unsigned i = 0; i < n; ++i) {
    	cin >> v[i];
    }

    bool dead = false;
    int cnt[100];
    bool dd[100];
    while(!dead) {
    	dead = true;
    	memset(cnt, 0, sizeof(cnt));
    	memset(dd, 0, sizeof(dd));
    	for(unsigned i = 0; i < n; ++i) {
	    	v[i]++;
	    	cnt[abs(v[i])]++;
	    	if (d[i])
	    		dd[abs(v[i])] = true;

	    	if (v[i] != 0 && v[i] < 100)
	    		dead = false;
    	}
    	//conflinct check (loc)
    	for(unsigned i = 0; i < 100; ++i) {
    		if (cnt[i] > 1) {
    			for(unsigned j = 0; j < n; ++j) {
    				if (v[j] == i) {
    					v[j] *= -1;
    					if (dd[i]) {
    						d[j] = true;
    					}
    				}
    			}
    		}
    	}
    }
    int ans = 0;
    for(unsigned i = 0; i < n; ++i) {
    	if (d[i])
    		ans++;
    }
    cout << ans;

	return 0;
}
