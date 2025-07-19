#include <bits/stdc++.h> 
using namespace std;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int x, y, z = 0;
	cin >> x >> y;
	for (int i = x; i <= y; i++) {
		int t = i;
		while (t) {
			if (t % 10 == 2) {
				z++;
			}
			t /= 10;			
		}

	}
	cout << z;
	return 0;
}