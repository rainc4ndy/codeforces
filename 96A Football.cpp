#include <algorithm>
#include <iostream>

int main(int argc, char const *argv[]) {
	
	using namespace std;

	string s; 
	cin >> s;

	int rep = 1;
	int rep_m = 1;
	for (int i = 0; i < s.length(); ++i) {
		if (i != s.length() - 1) {
			if (s[i] == s[i + 1]) {
				rep++;
				rep_m = max(rep, rep_m);
			} else {
				rep = 1;
			}
		}
	}
	
	cout << ((rep_m >= 7) ? "YES" : "NO");

	return 0;
}