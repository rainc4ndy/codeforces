#include <iostream>

int main(int argc, char const *argv[]) {
	
	using namespace std;

	string s;

	cin >> s;

    char words[] = {
    	'h', 'e', 'l', 'l', 'o'
    };

    int consist = 0;

	for (int i = 0; i < s.size(); ++i) {
		if (consist != 0) {
			if (s[i] != words[consist - 1]) {
				if (s[i] != words[consist]) {
					consist = 0;
				} else {
					consist++;
					cout << "consist++;" << endl;
					if (consist > 5) {
						cout << "YES";
						return 0;
					}
				}
			}
		}
		else if (s[i] == 'h') {
			consist++;
		}
	}
	cout << "NO";

	return 0;
}