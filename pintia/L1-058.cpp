#include <bits/stdc++.h> 
#include <iostream>
#include <sstream>
#include <string>
 
using namespace std;

int main() {
    

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	string s;
	std::getline(cin, s);

	bool flag = false;
	int c = 0;
	
	stringstream ss;

	for (int i = 0; i < s.length(); i++) {

		if (i == s.length() - 1) {
			if (flag) {
				c++;
				if (c > 3) {
					if (c > 9) {
						cout << "27";
					} else {
						cout << '9';
					}
				} else {
					cout << ss.str();
					cout << s[i];
				}
				ss.str(string());
				flag = false;
			} else cout << s[i];
			continue;
		}

		if (s[i] == '6') {
			if (!flag) {
				c = 0;
				flag = true;
			}
			c++;
			ss << '6';
		} else {
			if (flag) {
				if (c > 3) {
					if (c > 9) {
						cout << "27";
					} else {
						cout << '9';
					}
				} else {
					cout << ss.str();
				}
				ss.str(string());
				flag = false;
			} 
			cout << s[i];
		}
	}
	return 0;
}