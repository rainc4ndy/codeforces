#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
	
	using namespace std;

	int cases = 0;
	cin >> cases;

	std::vector<vector<int>> v;

	for (int i = 0; i < cases; ++i) {
		vector<int> tmp;
		v.push_back(tmp);

		int num = 0;
		cin >> num;
		for (int k = 0; k < num; ++k) {
			int n2 = 0;
			cin >> n2;
			v[i].push_back(n2);
		}
	}

	for (int i = 0; i < cases; ++i) {
		cout << ((v[i][0] > v[i][v[i].size() - 1]) ? "NO" : "YES") << endl;
	}


	return 0;
}