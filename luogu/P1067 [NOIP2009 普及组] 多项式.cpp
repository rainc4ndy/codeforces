#include <bits/stdc++.h>
using namespace std;

int xs[101] {}; //项的系数

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(unsigned i = 0; i < n + 1; ++i) {
    	cin >> xs[i];
    }

    bool flag = false;
    for(unsigned i = 0; i < n+1; ++i) {
    	if (xs[i] == 0)
    		continue;
    	if (flag) {
    		if (xs[i] >= 0)
    			cout << '+';
    		else
    			cout << '-';
    	} else {
    		if (xs[i] < 0)
    			cout << '-';
    		flag = true;
    	}
    	//n - 1 为指数
    	if (n - i != 0) {
    		if (abs(xs[i]) != 1)
	    		cout << abs(xs[i]);
	    	cout << 'x';
	    	if (n - i != 1) {
    			cout << '^' << n - i;
	    	}
    	} else {
    		cout << abs(xs[i]);
    	}
    }

	return 0;
}
