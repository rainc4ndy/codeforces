#include <iostream>

int main(int argc, char const *argv[]) {
	
	using namespace std;

	int p[6] {};
	int time = 0;
	bool flags[6][6] {};

	for (int i = 0; i < 6; ++i) {
		cin >> p[i];
		flags[i][p[i] - 1] = true; 
	}
	cin >> time;

	for (int i = 0; i < time; i++) {
		for (int j = 0; j < 6; j++) {
			for (int k = 5; k >= 0; k--) {
				if (!flags[j][k]) {
					flags[j][k] = true;
					p[j] = k + 1;
					break;
				}
			}
		}
	}
 
	for (int i = 0; i < 6; i++) {
		cout << p[i];
		if (i != 5) {
			cout << ' ';
		}
	}
	return 0;
}