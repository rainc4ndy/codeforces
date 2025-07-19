#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	string s, t;
	cin >> s >> t;

	int x = 0; //x 表示替换过程中，我们在 完整单词 中的位置

	// 遍历不完整的单词
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == t[x]) {
			//找到了相同的字符
			x++;
		}
		else if (s[i] == '?') {
			//问号，对我们有利，我们视他们相同
			s[i] = t[x];
			x++;
		}

		//如果替换早已完成，那么退出循环
		if (x >= t.size()) {
			break;
		}
	}

	// 如果我们的位置达到了 完整单词 的末尾，说明我们可以做到子序列
	if (x == t.size()) { 
		// 如果还有问号，把问号替换成a
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '?') {
				s[i] = 'a';
			}
		}
		cout << "YES" << endl;
		cout << s << endl;
	} else cout << "NO" << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _;
	cin >> _;
	while(_--) solve();

	return 0;
}