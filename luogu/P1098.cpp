#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int p1, p2, p3;
	string s;
	cin >> p1 >> p2 >> p3;

	cin >> s;
	stringstream ans;

	char pre, nxt;
	for (int i = 0; i < s.length(); i++) {
		if (i != s.length() - 1) {
			nxt = s[i + 1];
		}
		char c = s[i];
		if (c == '-') {
			int beg = pre + 1, end = nxt - 1;
			if (end - beg == 0)
				continue;
			//ASCII ORDER
			if (end - beg < 0) {
				ans << c;
				continue;
			}
			if (end )
			if (p3 == 2) {
				int tmp = beg;
				beg = end;
				end = tmp;
			}
			if (p1 == 1) {
				beg = tolower(beg);
				end = tolower(end);
			} else if (p1 == 2) {
				beg = toupper(beg);
				end = toupper(end);
			}

			if (beg < end) {
				for (char j = beg; j <= end; j++) {
					for (int k = 0; k < p2; k++) {
						if (p1 == 3) {
							ans << '*';
						} else {
							ans << j;
						}
					}
				}
			} else {
				for (char j = beg; j >= end; j--) {
					for (int k = 0; k < p2; k++) {
						if (p1 == 3) {
							ans << '*';
						} else {
							ans << j;
						}
					}
				}
			}
		} else {
			ans << c;
		}
		pre = c;
	}

	cout << ans.str();
	return 0;
}
