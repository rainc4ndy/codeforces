#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, tmp, sum;
    cin >> t;
    bool flag = false;

    vector<int> ans(t);
    for(unsigned i = 0; i < t; ++i) {
    	cin >> n;
    	sum = 0;
    	flag = false;
    	for(unsigned j = 0; j < n; ++j) {
    		cin >> tmp;
    		sum += tmp % 3;
    		if (tmp % 3 == 1)
    			flag = true;
    	}
    	sum %= 3;
    	if (sum == 0) {
    		ans[i] = 0;
    	} else if (sum == 2) {
			ans[i] = 1;
    	} else {
			ans[i] = flag ? 1 : 2;
    	}
    }

    for(unsigned i = 0; i < t; ++i) {
    	cout << ans[i];
    	if (i != t-1)
    		cout << endl;
    }

	return 0;
}
