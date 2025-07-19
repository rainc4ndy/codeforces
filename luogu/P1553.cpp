#include <bits/stdc++.h>

void rz(std::string& s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != '0') {
			s = s.substr(i, s.length() - i);
			break;
		}
	}
}

std::string flip(std::string s) {
	char tmp;
	int l = s.length();
	for (int i = 0; i < l / 2; i++) {
		tmp = s[i];
		s[i] = s[l - i - 1];
		s[l - i - 1] = tmp;
	}

	rz(s);
	return s;
}

int main() {

	using namespace std;
    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	string line;
	getline(cin, line);

	for (int i = 0; i < line.length(); i++) {
		if (line[i] == '.' || line[i]== '/') {
			string s1 = flip(line.substr(0, i));
			string s2 = flip(line.substr(i + 1, line.length() - i + 1));

			if (line[i] == '.' && s2[0] != '0') {
				for (int j = s2.length()-1; j >= 0; j--) {
					if (s2[j] == '0') {
						s2 = s2.substr(0, s2.length() - j);
						break;
					}
				}
			}

			cout << s1 << line[i] << s2;
			return 0; 
		}
		else if (line[i] == '%') {
			cout << flip(line.substr(0, i)) << '%';
			return 0; 
		}
	}

	cout << flip(line.substr(0, line.length()));

	return 0;
}
