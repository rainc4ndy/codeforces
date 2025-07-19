#include<iostream>
using namespace std;
int T;
int n, personNum;
int main() {
	cin >> T;
	for (int textIndex = 0; textIndex < T; textIndex++) {
		cin >> n >> personNum;
		int* fortNum = new int[n];
		
		for (int i = 0; i < n; i++) {
			cin >> fortNum[i];
		}
		int result_H = 0, wallNum = 0;
		for (int j = 1; j <= n; j++) {
			wallNum = 0;
			for (int i = 0; i < n; i++) {
				if (fortNum[i] >= j) {
					wallNum++;
					if (wallNum > j) {
						result_H = j;
						break;
					}
				}
			}
			if (wallNum <= j) {
				if (wallNum == j)result_H = j;
				break;
			}
		}
		int result = result_H * 10000 + personNum / 5;
		cout << result << endl;
	}
	return 0;
}