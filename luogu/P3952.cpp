#include <bits/stdc++.h> 
#include <cctype>
#include <deque>
#include <vector>
using namespace std;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int t;
	cin >> t;

	vector<int> ans(t, false);

	int n;
	char a, b, c, d;
	string tmp;
	int lps = 0;
	int ef = 0;

	for (int i = 0; i < t; i++) {

		ef = 0;
		lps = 0;
		queue<string> q;

		cin >> n;
		cin >> tmp;
		if (tmp[2] == 'n') {
			lps = tmp[4] - '0';
		} else {
			lps = 1;
		}

		cin.ignore();
		for (int j = 0; j < n; j++) {
			getline(cin, tmp);
			q.push(tmp);
		}
		ans[i] = 1;
		//offline
		bool varlist[256] {};

		int lps_cnt = 0;
		int lps_mx = 1;
		int w = 1;
		while (!q.empty()) {
			tmp = q.front();
			if (tmp.size() == 1) {
				if (!lps_cnt) {
					ans[i] = -1;
					break;
				}
				w--;
				lps_cnt--;
				q.pop();
				continue;
			} else {
				lps_cnt++;
				lps_mx = 1;
			}

			if (varlist[(int)tmp[2]]) { //重复变量
				ans[i] = -1;
				break;
			}
			varlist[(int)tmp[2]] = true;

			int sp = 0;
			for (int j = 3; j < tmp.size(); j++) {
				if (tmp[j] == ' ') {
					sp = j;
					break;
				}
			}

			if (isdigit(tmp[sp-1])) {

			}

			if (!isdigit(tmp[sp+1])) {
				w++;
				lps_mx = max(lps_mx, w);
			}

			q.pop();
		}
		if (lps_cnt) {
			ans[i] = -1;
		}
		else {
			cout << "lps_mx =" << lps_mx << endl; 
			ans[i] = lps == lps_mx;
		}
	}

	for (int i = 0; i < t; i++) {
		if (ans[i] == 1)
			cout << "Yes";
		else if (ans[i] == -1)
			cout << "Err";
		else 
			cout << "No";
		if (i != t-1)
			cout << endl;
	}

	return 0;
}