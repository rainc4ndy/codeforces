#include <bits/stdc++.h> 
#include <vector>
using namespace std;

#define mod (100001)
#define ll long long
#define x first
#define y second
typedef pair<int, int> P;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int n;
	cin >> n;

	vector<vector<int>> v(n, vector<int>(n, 0));
	vector<P> loc(n*n + 1);

	v[0][n/2] = 1;
	loc[1] = {0, n/2};

	for (int i = 2; i <= n*n; i++) {
		if (loc[i-1].x == 0 && loc[i-1].y != n-1) {

			loc[i] = {n-1, loc[i-1].y + 1};
			v[loc[i].x][loc[i].y] = i;

		} else if (loc[i-1].x != 0 && loc[i-1].y == n-1) {

			loc[i] = {loc[i-1].x - 1, 0};
			v[loc[i].x][loc[i].y] = i;

		} else if (loc[i-1].x == 0 && loc[i-1].y == n-1) {

			loc[i] = {loc[i-1].x + 1, loc[i-1].y};
			v[loc[i].x][loc[i].y] = i;

		} else if (loc[i-1].x != 0 && loc[i-1].y != n-1) {

			if (!v[loc[i-1].x - 1][loc[i-1].y + 1]) {
				loc[i] = {loc[i-1].x - 1, loc[i-1].y + 1};
				v[loc[i].x][loc[i].y] = i;
			} else {

				loc[i] = {loc[i-1].x + 1, loc[i-1].y};
				v[loc[i].x][loc[i].y] = i;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << v[i][j];
			if (j != n-1)
				cout << ' ';
		}
		if (i != n-1)
			cout << endl;
	}
	return 0;
}