#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<int> d1(n);
	vector<string> s(n);
	for(unsigned i = 0; i < n; ++i) {
		cin >> d1[i] >> s[i];
	}

	int ptr = 0, trg, direct;
	for(unsigned i = 0; i < m; ++i) {
		cin >> direct >> trg;

		if ((direct ^ d1[ptr]) == 1) {
			//forward
			ptr += trg;
			if (ptr >= n)
				ptr = ptr - n;
		} else {
			ptr -= trg;
			if (ptr < 0)
				ptr = n + ptr;
		}
	}
	cout << s[ptr];
	return 0;
}
