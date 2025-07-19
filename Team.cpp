#include <iostream>
#include <vector>

struct q {
	int i1;
	int i2;
	int i3;
};

int main(int argc, char const *argv[]) {
	using namespace std;

	int num = 0;
	cin >> num;

	vector<q> v;

	for (int i = 0; i < num; i++ ) {
		int d1, d2, d3;
		cin >> d1 >> d2 >> d3;
		q cache = {d1, d2, d3};
		v.push_back(cache);
	}

	int count = 0;
	for (int i = 0; i < num; i++) {
		if (v[i].i1 + v[i].i2 + v[i].i3 >= 2)
			count++;
	}

	cout << count;
	return 0;
}