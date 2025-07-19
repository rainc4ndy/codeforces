#include <bits/stdc++.h>

using namespace std;

bool num_or_c(char c) {
	return isdigit(c) || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int p1, p2, p3;
	cin >> p1 >> p2 >> p3;

	string s;
	cin >> s;

	map<int, string> m; //'-' 的位置和对应的替换字符串

	stringstream ss;
	for (unsigned i = 0; i < s.length(); ++i) {
		if (s[i] == '-' && i != 0 && i != s.length() - 1) {
			if (num_or_c(s[i+1]) && num_or_c(s[i-1]) && s[i+1] > s[i-1]) {
				ss.str("");
				for (unsigned j = s[i-1]+1; j <= s[i+1]-1; ++j) {
					for(unsigned k = 0; k < p2; ++k) { //重复次数
						switch (p1) {
							case 1: {
								ss << (char)tolower(j);
								break;
							}
							case 2: {
								ss << (char)toupper(j);
								break;
							}
							default:
								ss << '*';
						}
					}
				}
				m[i] = ss.str();
			}
		}
	}

	for (unsigned i = 0; i < s.length(); ++i) {
		if (s[i] == '-' && m.count(i) != 0) {
			cout << m[i];
		} else {
			cout << s[i];
		}
	}

	return 0;
}
