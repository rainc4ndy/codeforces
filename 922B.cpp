#include <bits/stdc++.h> 
using namespace std;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int n;
	cin >> n;
	int ans = 0;
	int vis[2501 * 3] {};
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			int z = x^y;
			if (0 < z && z <= n) {
				if (x + y > z &&
					x + z > y &&
					y + z > x) {
						ans++;
				}
			}
		}
	}
	cout << ans / 6;

	return 0;
}