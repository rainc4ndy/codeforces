#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
	
	using namespace std;

	
	int people, h;
	cin >> people >> h;

	vector<int> vh;

	for (int i = 0; i < people; ++i) {
		int tmp;
		cin >> tmp;
		vh.push_back(tmp);
	}

	int w = 0;
	for (int i = 0; i < people; ++i) {
		if (vh[i] <= h)
			w++;
		else
			w += 2;
	}

	cout << w;

	return 0;
}