#include <iostream>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
	
	using namespace std;
	std::vector<int> v;

	string s;
	std::getline(cin, s);
	int len = s.length();

	for (int i = 0; i < len; i++) {
		if (s[i] != '+') {
			v.push_back((int)(s[i] - 48));
		}
	}

	int num = v.size();
	for (int i = 0, cache = 0; i < num; i++) {
		for (int j = 1; j < num - i; j++) {
			if (v[j - 1] > v[j]) {
				cache = v[j - 1];
				v[j - 1] = v[j];
				v[j] = cache;
			}
		}
	}

	for (int i = 0; i < num; i++) {
		cout << v[i] << ((i == num - 1) ? "" : "+");
	}

	return 0;
}