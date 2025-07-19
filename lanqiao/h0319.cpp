#include <bits/stdc++.h> 
using namespace std;

const int mod = 5002;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;
typedef unsigned short us;

us w[mod][mod] {};

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int n, r;
	cin >> n >> r;

	int x,y,z;
	int mx = 0, my = 0;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y >> z;
		x++;
		y++;
		w[x][y] += z;
	}

	for (int i = 1; i <= 5001; i ++)
		for (int j = 1; j <= 5001; j ++)
			w[i][j] = w[i - 1][j] + w[i][j - 1] - w[i - 1][j - 1] + w[i][j];
	
	us ans = 0;
	for (int i = r; i <= 5001; i ++) {
		for (int j = r; j <= 5001; j ++) {
			us num = w[i][j] - w[i - r][j] - w[i][j - r] + w[i - r][j - r];
			ans = max(ans, num);
		}
	}

	cout << ans;

	return 0;
}