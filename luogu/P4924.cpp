#include <bits/stdc++.h>
using namespace std;

int matrix[501][501] {};
int m2[501][501] {};

void pm(int sz) {
	cout << "------------------------" << endl;
	for(unsigned i = 0; i < sz; ++i) {
		for(unsigned j = 0; j < sz; ++j) {
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}

void rotate(int x, int y, int sz, int n, bool right) {
	int tmp;
	memcpy(m2, matrix, sizeof(matrix));

	cout << "m = " << matrix[x][y] << endl;
	cout << "x + sz = " << x + sz << endl;

	if (right) {
		for(unsigned i = x; i < x + sz; ++i) {
			for(unsigned j = y; j < y + sz; ++j) {
				m2[j][(x + sz) - 1 - i] = matrix[i][j];
			}
		}
	} else {
		for(unsigned i = x; i < x + sz; ++i) {
			for(unsigned j = y; j < y + sz; ++j) {
				m2[(y + sz) - 1 - j][i] = matrix[i][j];
			}
		}
	}
	memcpy(matrix, m2, sizeof(matrix));
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int row = 0, col = 0;
	for(unsigned i = 0; i < pow(n, 2); ++i) {
		matrix[row][col++] = i + 1;
		if ((i + 1) % 5 == 0) {
			col = 0;
			row++;
		}
	}

	rotate(1, 1, 3, n, true);
	pm(n);

	int x, y, s, d;
	for(unsigned i = 0; i < m; ++i) {
		cin >> x >> y >> s >> d;
		rotate(x - s - 1, y - s - 1, 2 * s + 1, n, d == 0);
		pm(n);

	}

	pm(n);
	return 0;
}
