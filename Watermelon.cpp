#include <iostream>

int main() {

	using namespace std;

	int w; 
	cin >> w;

	int i1 = 1, i2 = w - 1;
	while (i1 != w || i2 != 0) {
		if (i1 % 2 == 0 && i2 % 2 == 0) {
			cout << "YES";
			return 0;
		}
		i1++;
		i2--;
		//cout << "i1 = " << i1 << "  i2 = " << i2 << endl;
	}
	cout << "NO";

	return 0;
}