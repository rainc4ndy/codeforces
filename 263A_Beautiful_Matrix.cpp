#include <iostream>

int main(int argc, char const *argv[]) {
	
	using namespace std;

	int location[2];
	for(int i = 0; i < 5; i++) {
		for (int j = 0, c = 0; j < 5; j++) {
			cin >> c;
			if (c == 1) {
				location[0] = i;
				location[1]= j;
			}
		}
	}

	int moves = 0;
	moves += (location[0] < 2) ? (2 - location[0]) : (location[0] - 2);
	moves += (location[1] < 2) ? (2 - location[1]) : (location[1] - 2);

	cout << moves;
	return 0;
}