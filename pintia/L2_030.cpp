#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct st {
	vector<string> child;
	bool sex;
};
unordered_map<string, st> m;

bool dfs(string root, int r, string &trg, vector<string> &path) {
	if (m[root].child.size() == 0) {
		return false;
	}

	for (auto it : m[root].child) {
		if (dfs(it, r + 1, trg, path)) {
			path.push_back(it);
			return true;
		}
	}
	path.pop_back();
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string s1, s2, s3, s4;
	//如果是儿子就加 sson，女儿则加 sdottir
	//其他人则是在姓的后面加 m 表示男性、f 表示女性
	//孩子的姓等于父亲的名加后缀
	//题目保证不存在两个人是同名的

	string root;
	for (int i = 0; i < n; i++) {
		cin >> s1 >> s2;

		int loc;
		if ((loc = s2.find("sson")) != string::npos) {
			m[s2.substr(0, loc)]
			.child
			.push_back(s1);

			m[s1].sex = true;
		} else if ((loc = s2.find("sdottir")) != string::npos) {
			m[s2.substr(0, loc)]
			.child
			.push_back(s1);

			m[s1].sex = false;
		} else if (s2[s2.length() - 1] == 'm') {
			root = s2.substr(0, s2.length() - 1);
			m[root]
			.child
			.push_back(s1);

			m[s1].sex = true;
		} else {
			m[s2.substr(0, s2.length() - 1)]
			.child
			.push_back(s1);

			m[s1].sex = false;
		}
	}

	int k;
	cin >> k;
	vector<int> ans(k);
	vector<string> sq1, sq2;

	for (int i = 0; i < k; i++) {
		cin >> s1 >> s2 >> s3 >> s4;

		if (!m.count(s1) || !m.count(s3)) {
			ans[i] = 3;
			continue;
		}
		if (m[s1].sex == m[s3].sex) {
			ans[i] = 2;
			continue;
		}

		sq1.clear();
		sq2.clear();

		sq1.push_back(root);
		sq2.push_back(root);

		dfs(root, 0, s1, sq1);
		dfs(root, 0, s3, sq2);

		cout << endl << "sq1:" << endl;
		for (auto it : sq1) {
			cout << it << endl;
		}
		cout << "sq2:" << endl;
		for (auto it : sq2) {
			cout << it << endl;
		}
	}

	for (int i = 0; i < k; i++) {
		switch (ans[i]) {
		case 0:
			cout << "Yes";
			break;
		case 1:
			cout << "No";
			break;
		case 2:
			cout << "Whatever";
			break;
		case 3:
			cout << "NA";
			break;
		}
		if ( i !=k-1)
			cout << endl;
	}

	return 0;
}