#include <iostream>

int main(int argc, char const *argv[]) {
	
	using namespace std;

	int w1, w2;
	cin >> w1 >> w2;

	int y = 0;

	while (w1 <= w2) {
		w1 *= 3;
		w2 *= 2;
		y++;
	}

	cout << y;

	return 0;
}