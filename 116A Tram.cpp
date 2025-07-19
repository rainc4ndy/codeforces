#include <iostream>

int main(int argc, char const *argv[]) {
	
	using namespace std;

	int num;
	cin >> num;

	int max, in, out, people = 0;
	max = 0;
	for (int i = 0; i < num; ++i) {
		cin >> out >> in;
		people += in;
		people -= out;
		if (people > max) {
			max = people;
		}
	}
	cout << max;

	return 0;
}