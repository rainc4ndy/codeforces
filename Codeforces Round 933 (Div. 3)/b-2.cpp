#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin >> t;
	int n,m,x;
	bool v[1001][1001]; //记录每次投球后的每个人持球的状态

	int steps;
	char dir;
	for(unsigned i = 0; i < t; ++i) {
		cin >> n >> m >>x;
		memset(v, 0, sizeof(v));

		v[0][x - 1] = 1;

		for(unsigned j = 0;  j< m; ++j) {
			cin >> steps >> dir;

			if (dir == '0') {
				v[j][(j + steps) % n] = 1;
			} else if (dir == '1') {
				v[j][(j - steps + n) % n] = 1;
			} else {
				v[j][(j + steps) % n] = 1;
				v[j][(j - steps + n) % n] = 1;
			}
		}
	}

	return 0;
}
