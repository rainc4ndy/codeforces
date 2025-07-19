#include <bits/stdc++.h>
using namespace std;

const int SZ = 1001;
int v[SZ], len = 0;
map<int, int> rec; //记录元素在数组中的位置

void heaplify(int num) {

	v[++len] = num;
	int pos = len;
	while (pos > 1) {
		if (v[pos] < v[pos / 2])  {
			swap(v[pos], v[pos / 2]);
 			pos /= 2;
			continue;
		}
		break;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, tmp;
	cin >> n >> m;
	for (int i  = 0; i < n; i++) {
		cin >> tmp;
		heaplify(tmp);
	}
	for(unsigned i = 1; i <= n; ++i) {
		rec[v[i]] = i;
	}
	vector<char> ans(m);

	int x, y, t, l, e;
	string s;
	stringstream ss;
	for (unsigned i = 0; i < m; ++i) {
		cin >> x;
		getline(cin, s);

		t = x;
		l = 0;
		while (t) {
			t /= 10;
			l++;
		}

		if (s.find("root") != string::npos) {
			ans[i] = v[1] == x ? 'T' : 'F';
		} else {
			ss.clear();
			ss.str("");
			for(unsigned j = l-1; j < s.size(); ++j) {
				if (isdigit(s[j]) || s[j] == '-') {
					e=j;
					break;
				}
			}
			ss << s.substr(e, s.length() - e);
			ss >> y;

			if(rec.count(x) == 0 || rec.count(y) == 0) {
				ans[i] = 'F';
				continue;
			}

			int i1 = rec[x], i2 = rec[y];

			if (s.find("siblings") != string::npos) {
				ans[i] = v[i1 / 2] == v[i2 / 2] && i1 != i2 ? 'T' :'F';
			} else if (s.find("parent") != string::npos) {
				ans[i] = v[i1] == v[i2 / 2] ? 'T' :'F';
			} else if (s.find("child") != string::npos) {
				ans[i] = v[i1 / 2] == v[i2] ? 'T' :'F';
			}
		}
	}

	for (unsigned i = 0; i < m; ++i) {
		cout << ans[i];
		if (i != m - 1)
			cout << endl;
	}
	return 0;
}
