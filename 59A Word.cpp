#include <iostream>

int main(int argc, char const *argv[]) {
	
	using namespace std;

	string s;
	cin >> s;

	int up = 0, down = 0;
	for (int i = 0; i < s.length(); ++i) {
		if ('a' <= s[i] && s[i] <= 'z') {
			down++;
		} else{
			up++;
		}
	}

	for (int i = 0; i < s.length(); ++i) {
		if ('a' <= s[i] && s[i] <= 'z') {
			cout << static_cast<char>((int)s[i] + ((up > down) ? -32 : 0));
		} else if ('A' <= s[i] && s[i] <= 'Z') {
			cout << static_cast<char>((int)s[i] + ((up <= down) ? 32 : 0));
		}
	}
	
	return 0;
}