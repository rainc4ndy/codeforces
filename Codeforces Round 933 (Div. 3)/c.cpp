#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin >> t;
	int n;
	string s;

	int a = 0;
	vector<int> ans(t);
	for(unsigned i = 0; i < t; ++i) {
		cin >> n;
		cin >> s;

		a = 0;
		if (s.find("map") == string::npos && s.find("pie") == string::npos) {
			ans[i] = 0;
			continue;
		}

		size_t position = 0;
		while ((position = s.find("mapie", position)) != string::npos) {
			a++;
			position+=5;
		}

		position = 0;
		while ((position = s.find("map", position)) != string::npos) {
			ans[i]++;
			position+=3;
		}

		position = 0;
		while ((position = s.find("pie", position)) != string::npos) {
			ans[i]++;
			position+=3;
		}
		ans[i] -= a;
	}

	for(unsigned i = 0; i < t; ++i) {
		cout << ans[i];
		if (i != t- 1)
			cout << endl;
	}

	return 0;
}
