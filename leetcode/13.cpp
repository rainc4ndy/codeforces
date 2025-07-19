#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		int m[128] {};
		m['I'] = 1;
		m['V'] = 5;
		m['X'] = 10;
		m['L'] = 50;
		m['C'] = 100;
		m['D'] = 500;
		m['M'] = 1000;
		int ans = 0;
		for (int i = 0; i < s.length(); i++) {
			char c = s[i];
			if (i != s.length() - 1) {
				char n = s[i + 1];
				if (c == 'I' && (n == 'V' || n == 'X')) {
					ans += m[n] - m[c];
					i++; //skip
				} else if (c == 'X' && (n == 'L' || n == 'C')) {
					ans += m[n] - m[c];
					i++; //skip
				} else if (c == 'C' && (n == 'D' || n == 'M')) {
					ans += m[n] - m[c];
					i++; //skip
				} else {
					ans += m[c];
				}
			} else {
				ans += m[c];
			}
		}
		return ans;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Solution cl;

	string s;
	cin >> s;
	cout << cl.romanToInt(s);
	return 0;
}
