#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define No cout << "No" << endl;
#define Yes cout << "Yes" << endl;
#define all(x) x.begin(),x.end()

int n;
bool ok (int x)
{
	return 1 <= x && x <= n;
}


void solve() {
	string s;
	cin >> s;

	vector<pair<int, int>> v;

	if (s[0] == '-') {
		No;
		return;
	}
	if (count(all(s),'-') == 0) {
		No;
		return;
	}
	n = s.size();
	for (int i = n-1; i >= 0; i--) {
		if (s[i] == '-') {
			if (i >= n-3) {
				No;
				return;
			}
		}
	}

	s = ' ' + s;

	int end = 0;
	for (int i = n - 2; i >= 1; i --)
	{
		if (s[i] == '-')
		{
			break;
		}
		end = i;
		v.push_back({1, i + 2});
	}

	for (int i = 2; i <= end - 2; i++)
	{
		if (s[i] == '>')
		{
			v.push_back({i, end + 2 + 1 - i});
		}
	}

	cout << "Yes " << v.size() << "\n";
	for (auto &x : v)
	{
		cout << x.first << " " << x.second << "\n";
	}
}

int main() {

	int _ = 0;
	cin >> _;
	while (_--) {
		solve();
	}
	return 0;
}