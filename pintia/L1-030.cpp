#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

	list<pair<string, int>> l;
	int tmp;
	string s;
	for(unsigned i = 0; i < n; ++i) {
		cin >> tmp;
		cin >> s;
		l.emplace_back(make_pair(s, tmp));
	}

	while (!l.empty()) {
		for(auto it = prev(l.end()); it != l.begin(); it--) {
			if (l.front().second ^ it->second) {
				cout << l.front().first << ' ' << it->first;
				l.pop_front();
				l.erase(it);
				break;
			}
		}
		if (l.size() != 0)
			cout << endl;
	}


	return 0;
}
