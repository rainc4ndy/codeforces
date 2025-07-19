#include <cstring>
#include <iostream>

int main(int argc, char const *argv[]) {
	
	using namespace std;

	string s;

	cin >> s;

	bool flags[256] {};
	int c = 0;

	for (int i = 0; i < s.length(); i++) {
		if (flags[(int)s[i]] == false) {
			flags[(int)s[i]] = true;
			c++;
		}
	}

	cout << ((c % 2 == 0) ? "CHAT WITH HER!" : "IGNORE HIM!");

	return 0;
}