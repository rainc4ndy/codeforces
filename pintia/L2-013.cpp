#include <bits/stdc++.h>
using namespace std;

const int SZ = 500;
bool dp[SZ][SZ] {}; //dp[i][j] 表示城市i是否有通向j的道路
int dp2[SZ]; //dp2[i] 表示城市i到其他城市的道路数量
int cnt = 0; //总道路数量

int n, m;

//攻占城市
void f(int num) {
	for(unsigned i = 0; i < n; ++i) {
		if (dp[i][num] && dp[i][num]) {
			dp2[i]--;
			dp[i][num] = dp[num][i] = false;
		}
	}
	cnt -= dp2[num];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n >>m;
	int x,y,z,k;
	for(unsigned i = 0; i < m; ++i) {
		cin >> x >> y;

		//道路是双向的
		if (!dp[x][y] || !dp[y][x]) { //去重
			cnt++;
			dp2[x]++;
			dp2[y]++;
		}
		dp[x][y] = dp[y][x] = true;
	}

	bool flag = false;
	bool isolated = cnt == 0;

	cin >> k;
	for(unsigned i = 0; i < k; ++i) {
		cin >> z;
		if (cnt)
			f(z);

		if (!cnt && !flag && !isolated) {
			cout << "Red Alert: City " << z << " is lost!";
			flag = true;
		} else {
			cout << "City " << z << " is lost.";
		}

		if (i != k-1) {
			cout << endl;
		} else if (k == n)
			cout << endl << "Game Over.";
	}

	return 0;
}
