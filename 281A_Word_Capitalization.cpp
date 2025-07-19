#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
	using namespace std;
	string s;

	getline(cin, s);

	char c = s[0];
	c += ('a' <= c && c <= 'z') ? -32 : 0;

	cout << c << s.substr(1, s.length());
	return 0;
}