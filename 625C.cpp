#include <bits/stdc++.h> 
using namespace std;

int v[501][501];

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int n, k;
	cin >> n >> k;

	int r = n*n;
	r -= (n-k);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		v[i][k] = r;
		sum += v[i][k];

		for (int j = k+1; j <= n; j++) {
			v[i][j] = v[i][j-1] + 1;
		}

		r -= (n-k+1);
	}

	int d = v[n][k]-1;
	for (int i = 1; i <= n; i++) {
		for (int j = k-1; j >= 1; j--) {
			v[i][j] = d--;
		}
	}

	cout << sum << endl;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << v[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}