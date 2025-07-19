#include <bits/stdc++.h> 
#include <cstdio>
  
#define mod (1001)

/*a≤x≤b
b≤y≤c
c≤z≤d
There exists a triangle with a positive non-zero area 
and the lengths of its three sides are x, y, and z
.*/

using namespace std;

int t;
int a[mod], b[mod], c[mod], d[mod];
int ans[3] {};

inline bool triangle(int a, int b, int c) {
	return ((a + b > c) && (a + c > b) && (b + c > a));
}

void solve() {
	bool flag;
	for (int i = 0; i < t; i++) {
		flag = false;
    	for (int i2 = b[i]; i2 >= a[i]; i2--) {
    		for (int i3 = c[i]; i3 >= b[i]; i3--) {
    			for (int i4 = d[i]; i4 >= c[i]; i4--) {
    				if (triangle(i2, i3, i4)) {
    					ans[0] = i2;
    					ans[1] = i3;
    					ans[2] = i4;

    					printf("%d %d %d", ans[0], ans[1], ans[2]);
    					if (i != t - 1)
    						putchar('\n');
    					
    					flag = true;
    					break;
    				}
				}
				if (flag) break;
    		}
			if (flag) break;
    	}
    }
}

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    cin >> t;

    for (int i = 0; i  < t; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    solve();
	return 0;
}