#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
	
	using namespace std;

	string s, s2;
	std::getline(cin, s);
	std::getline(cin, s2);

	int len = s.length();

	char tmp = 0;
	for (int i = 0; i < len / 2; ++i) {
		//cout << s[i] << " = " << s[len - i - 1] << endl;
		tmp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = tmp;
	}

	//cout << s << endl;
	cout << ((s == s2) ? "YES" : "NO");

	return 0;
}