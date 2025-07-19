#include <bits/stdc++.h>

int main() {

	using namespace std;

	int t;
	cin >> t;

	char oper, lc;
	int o;

	vector<string> ans;

	string s;

	cin.ignore();


	for (int i = 0; i < t; i++) {

		vector<string> v;
		std::getline(cin, s);

		size_t pos = 0;
		while ((pos = s.find(' ')) != std::string::npos) {
		    v.push_back(s.substr(0, pos));
		    s.erase(0, pos + 1);
		}
		v.push_back(s);


		if (!isdigit(v[0][0])) {
			int a = atoi(v[1].c_str()), b = atoi(v[2].c_str());
			if (v[0][0] == 'a') {
				oper = '+';
				o = a + b;
			} else if (v[0][0] == 'c') {
				oper = '*';
				o = a *b;
			} else if (v[0][0] == 'b') {
				oper = '-';
				o = a - b;
			}
			stringstream ss;
			ss << a << oper << b << '=' << o;
			ans.push_back(ss.str());
			lc = v[0][0];
		} else {
			int a = atoi(v[0].c_str()), b = atoi(v[1].c_str());
			if (lc == 'a') {
				oper = '+';
				o = a + b;
			} else if (lc == 'c') {
				oper = '*';
				o = a *b;
			} else if (lc == 'b') {
				oper = '-';
				o = a - b;
			}
			stringstream ss;
			ss << a << oper << b << '=' << o;
			ans.push_back(ss.str());
		}
	}

	for (int i = 0; i < t; i++) {
		cout << ans[i] << endl << ans[i].length();
		if (i != t - 1)
			cout <<endl;
	}

	return 0;
}