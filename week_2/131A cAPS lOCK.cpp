#include <iostream>

char isUpper(char c) {
	return (c >= 'A' && c <= 'Z');
}

int main(int argc, char const *argv[]) {
	
	using namespace std;

	string s;
	cin >> s;

	//upper 
	int len = s.length();

	int upc = 0;
	int head = 0;
	int end = 0;
	bool flag = false;
	while (end != len) {

		if (isUpper(s[head])) {

		} else {
			s
		}
	
		end++;
	}

	cout << s;


	return 0;
}