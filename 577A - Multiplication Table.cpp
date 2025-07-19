#include <bits/stdc++.h> 
  
int main() {
    using namespace std;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

   /* int n, x;
    cin >> n >> x;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
    	for (int k = 1; k <= n; k++) {
    		if (x == i * k) {
    			ans++;
    		}
    	}
    }
    cout << ans;
*/
    int n, x, c(0);
    cin >> n >> x;

    // n = 6,   x = 12
    // n = 10,   x = 5
    for (int i = 1; i <= n; i++)
        if (x % i == 0 && x / i <= n) c++;

    cout << c << endl;
	return 0;
}