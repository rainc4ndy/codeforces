#include <iostream>

int main(int argc, char const *argv[]) {
	
	using namespace std;

	string s;
	cin >> s;

	long long  b = 0, c = 0;

	for (int i = 0; i < s.length(); ++i) {
		b += (s[i] == '7');
		c += (s[i] == '4');
	}

	long long f = b + c;
	//cout << "f = " << f << endl;
	if ((f == 4 || f == 7))
		cout << "YES";
	else
		cout << "NO";

	return 0;
}