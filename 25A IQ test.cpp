#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
	
	using namespace std;

	int num = 0;

	cin >> num;

	std::vector<int> v;

	int evenness[2] {};

	for (int i = 0; i < num; i++) {
		int t;
		cin >> t;
		if (t % 2 == 0) {
			evenness[0]++;
		} else evenness[1]++;

		v.push_back(t);
	}

	bool finder = (evenness[0] > evenness[1]);
	// true: 偶多
	// false: 奇数多;
	//cout << finder << endl;

	for (int i = 0; i < v.size(); ++i) {
		if (finder) {
			if (v[i] % 2 != 0) {
				cout << i + 1;
				break;
			}
		} else {
			if (v[i] % 2 == 0) {
				cout << i + 1;
				break;
			}
		}
	}

	return 0;
}