#include <iostream>
#include <string>
#include <sstream>
#include <map>

int main(int argc, char const *argv[]) {
	
	using namespace std;

	std::map<char, char> m = {
		{'A', '.'},
		{'O', '.'},
		{'Y', '.'},
		{'E', '.'},
		{'U', '.'},
		{'I', '.'},
		{'a', '.'},
		{'o', '.'},
		{'y', '.'},
		{'e', '.'},
		{'u', '.'},
		{'i', '.'}
	};

	string s; 
	cin >> s;

	stringstream ss;

	int len = s.length();
	for (int i = 0; i < len; ++i) {
		if (m.count(s[i]) == 0) {
			ss << s[i];
		}
	}

	string s2 = ss.str();
	for (int i = 0, i2 = 0; i < s2.length() * 2; ++i, i2 ^= 1) {
		char c = s2[i / 2];
		c += ('A' <= c && c <= 'Z') ? 32 : 0; 
		cout << ((i2 == 0) ? '.' : c);
	}

	return 0;
}