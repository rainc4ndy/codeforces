#include <bits/stdc++.h>
using namespace std;

void g(string &s, string origin, string trg) {
	int pos = 0;
	bool b1 = false, b2 = false, b3 = false, b4 = false;
	while ((pos = s.find(origin, pos)) != string::npos) {
		b1 = pos == 0;
		b2 = pos + origin.length() == s.length();

		if (s[pos - 1] == ' ' || ispunct(s[pos - 1]))
			b3 = true;
		if (s[pos + origin.length()] == ' ' ||
			ispunct(s[pos + origin.length()]))
			b4 = true;

		if ((b4 && b3) || (b1 && b4) || (b2 && b3) || (b1 && b2))
			s.replace(pos, origin.length(), trg);
		else
			pos +=origin.length();
	}
}

void f(string &s) {

	bool flag = false;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ' ') {
			s.erase(0, i);
			flag = true;
			break;
		}
	}
	for (int i = s.length() - 1; i >= 0; i--) {
		if (s[i] != ' ') {
			s.erase(i + 1, s.length() - i);
			flag = true;
			break;
		}
	}
	if (!flag) {
		s = "";
		return;
	}

	int rear = 0, front = 0, space = 0;

	//消除原文中多余空格：把相邻单词间的多个空格换成 1 个空格，把标点符号前面的空格删掉
	while (front != s.length()) {
		if (s[front] == ' ') {
			if (space == 0) {
				rear = front;
			}
			space++;
		} else if (space != 0) {
			if (ispunct(s[front])) {
				s.erase(rear, space);
				front -= space; //指针也减去多的空格数量
			} else if (space > 1) {
				s.erase(rear, space - 1);
				front -= space - 1;
			}

			space = 0;
			rear = front;
		}
		front++;
	}

	for (int i = 0; i < s.length(); i++) {
		if (s[i] != 'I')
			s[i] = tolower(s[i]);
		if (s[i] == '?')
			s[i] = '!';
	}

	g(s, "I", "you");
	g(s, "me", "you");

	g(s, "can you", "I can");
	g(s, "could you", "I could");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<string> v(n);
	cin.ignore();
	for (unsigned i = 0; i < n; ++i) {
		std::getline(cin, v[i]);
	}
	for (unsigned i = 0; i < n; ++i) {
		cout << v[i] << endl;
		f(v[i]);
		cout << "AI: " << v[i];
		if (i != n - 1)
			cout << endl;
	}
	return 0;
}
