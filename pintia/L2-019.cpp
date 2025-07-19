#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;
	string s;
	set<string> m;
	for(unsigned i = 0; i < n; ++i) {
		cin >> s;
		m.insert(s);
	}

	int k, sc, sum = 0, average;
	cin >> k;

	map<string, int> a;
	for(unsigned i = 0; i < k; ++i) {
		cin >> s >> sc;
		a[s] += sc;
		sum += sc;
	}
	average = sum / k;

	bool flag = false;

	for (auto it = a.begin(); it != a.end(); it++) {
		if (it->second > average && m.count(it->first) == 0) {
			cout << it->first;
			flag = true;
			if (it != prev(a.end())) {
				cout << endl;
			}
		}
	}
	if (!flag) {
		cout << "Bing Mei You";
		return 0;
	}

	return 0;
}
