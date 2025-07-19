#include <cstring>
#include <iostream>
#include <vector>
int main(int argc, char const *argv[]) {
	
	using namespace std;

	int n;
	cin >> n;

	int *v = new int[n];
	bool *gone = new bool[n];
	memset(gone, 0, n * sizeof(bool));

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	int cars[4] {};

	for (int i = 0; i < n; ++i) {
		if (v[i] == 3) { 
			for (int j = 0; j < n; j++) {
				if (v[j] == 1 && !gone[j]) {
					cars[3]++;
					gone[j] = true;
				}
			}
		}
		else if (v[i] == 2) { 
			for (int j = 0; j < n; j++) {
				if (v[j] == 2 && !gone[j]) {
					cars[2]++;
					gone[j] = true;
				}
			} 
		}
		else if (v[i] == 1) { 
			for (int j = 0; j < n; j++) {
				if (v[j] == 1 && !gone[j]) {
					cars[1]++;
					gone[j] = true;
				}
			}
		}
	}

	cout << cars[0] + cars[1] + cars[2] + cars[3]; 

	return 0;
}