#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin >> t;
	int sz;
	int m[10001][10001] {};
	for(int i =0 ; i < t; i++) {
		cin >> sz;
		for(int j = 0; j < 2; ++j) {
			for(int k = 0; k < sz; ++k) {
				cin >> m[j][k];
			}
		}

		int p1 = 0, p2 = 0; //r, c
		while (p1 != 1 && p2 != sz - 1) {

		}
	}

	return 0;
}
