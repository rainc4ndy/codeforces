#include <cwchar>
#include <iostream>

int main(int argc, char const *argv[]) {

	using namespace std;
	int num = 0;

	cin >> num;

	cin.ignore();

	int x = 0;

	string s;
	int len  = 0;
	for (int i = 0; i < num; i++) {
		std::getline(cin, s);

		len = s.length();

		if (s[0] == 'X') {
			x += (s[len - 1] == '+') ? 1 : -1;
		}
		if (s[len - 1] == 'X') {
			x += (s[0] == '+') ? 1 : -1;
		}
	}
	cout << x;
	return 0;
}
