#include <bits/stdc++.h> 

using namespace std;

int m[200001] {};
int sum[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int f(int integer) {
	if (integer < 10) {
		return integer;
	}
	return ((integer % 10) + f(integer / 10));
}

int main() {
    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int t;
	cin >> t;

	vector<long long> ans(t);

	for (int j = 1; j < 200001; j++) {
		m[j] = m[j - 1] + f(j);
	}

	int n;
	int mx = 0;
	for (int i = 0; i < t; i++) {
		cin >> n;
		/*int j = 1;

    	if (n > mx) {
    		j = mx + 1;
	    	ans[i] = m[mx];
    	} else {
    		for (int k = n; k >= 0; k--) {
	    		if (m[k] != 0) {
	    			j = k + 1;
	    			ans[i] = m[k];
	    			break;
	    		}
	    	}
    	}

		for (; j <= n; j++) {
			ans[i] += f(j);
		}
		m[n] = ans[i];
		mx = max(mx, n);*/
		ans[i] = m[n];
	}
	for (int i = 0; i < t; i++) {
		cout << ans[i];
		if (i != t -1)
			cout << endl;
	}
	return 0;
}
