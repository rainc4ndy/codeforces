#include <bits/stdc++.h> 
  
int main() {
    using namespace std;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int row1, column1;
	cin >> row1 >> column1;

	int *m1 = new int[row1 * column1];
	for (int i = 0; i < row1 * column1; i++) {
		cin >> m1[i];
	}

	int row2, column2;
	cin >> row2 >> column2;

	int *m2 = new int[row2 * column2];
	for (int i = 0; i < row2 * column2; i++) {
		cin >> m1[i];
	}

	if (column1 != row2) {
		cout << "Error: " << column1 << " != " << row2;
	} else {
		int *m3 = new int[row1 * column2];
		for (int i = 0; i < row1 * column2; i++) {
			// 计算每一个元素
			// 行乘列
			(row1 * column2) / (i + 1);
			for (int j = 0; j < column1; i++) {
				for (int k = 0; k < row2; k++) {
					m3[i] += m1[j] * m2[k];
				}
			}
		}
		delete[] m3;
	}

	delete[] m1;
	delete[] m2;


	return 0;
}