#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

int main() {

	using namespace std;

	int num = 0;
	cin >> num;
	getchar();

	std::vector<string> v;

	for (int i = 0; i < num; i++) {
		string tmp;
		getline(cin, tmp);

		v.push_back(tmp);
	}

	for (int i = 0; i < num; i++) {
		const char *ptr = v[i].c_str();
		int len = v[i].length();
		if (len > 10) {
			cout << ptr[0] << len - 2 << ptr[len - 1];
		} else {
			cout << v[i];
		}
		if (i != num - 1)
			cout << endl;
	}
		
	return 0;
}	