#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
	
	using namespace std;
	int n = 0, k = 0;

	cin >> n >> k;
 
 	vector<int> v;

	for (int i = 0; i < n; i++) {
		int j = 0;
		cin >> j;
		v.push_back(j);
	}

	int c = 0;
	int standard = v[k - 1];
	for (int i = 0; i < n; i++) {
		if (v[i] <= 0)
			continue;
		if (v[i] >= standard)
			c++;
	}

	cout << c;
	return 0;
}