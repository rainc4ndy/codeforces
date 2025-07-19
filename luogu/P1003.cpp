#include <bits/stdc++.h> 
#include <vector>
using namespace std;

#define mod (100001)
#define ll long long
#define x first
#define y second
typedef pair<int, int> P;

int a[mod],b[mod],g[mod],k[mod];

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> g[i] >> k[i];
	}

	int x, y;
	cin >> x >> y;

	for (int i = n-1;i >= 0; i--) {
		if (x >= a[i] && x <= a[i]+g[i] && y >= b[i] && y <= b[i]+k[i]) {
			cout << i+1;
			return 0;
		}
	} 

	cout << -1;
	return 0;
}