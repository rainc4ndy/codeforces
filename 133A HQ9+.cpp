#include <bits/stdc++.h> 
#include <string>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	char d[] = {
		'H', 'Q', '9'
	};

	int l = sizeof(d) / sizeof(char);

	string s;
	cin >> s;
	bool any = false;
	for (int i = 0; i < s.length();i++) {
		for (int j = 0; j < l; j++) {
			if (s[i] == d[j]) {
				any = true;
				break;
			}
		}
	}
	cout << (any ? "YES" : "NO");

	return 0;
}