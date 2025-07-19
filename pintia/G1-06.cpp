#include <bits/stdc++.h>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		char nxt = s[i + 1];
		if (nxt == s[i]) {
			cnt++;
		} else {
			if (cnt > 0 && cnt < 9) {
				cout << s[i] << cnt + 1;
			} else if (cnt >= 9) {
				for (int j = 0; j < cnt + 1; j++) {
					cout << s[i];
				}
			} else {
				cout << s[i];
			}
			cnt = 0;
		}

	}
	return 0;
}