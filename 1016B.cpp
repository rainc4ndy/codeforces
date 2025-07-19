#include <bits/stdc++.h> 
using namespace std;

// 前缀和
const int mod = 1e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

ll pa[mod] {};

void solve() {
	ll n, m, q;
	cin >> n >> m >> q;

	string s, t;
	cin >> s >> t;
	s.insert(s.begin(), ' '); 
	t.insert(t.begin(), ' '); 

	// 查找t在s中的所有位置
	for (int i = 1; i + m - 1 <= n; ++i) {
		// 如果从s的第i个位置开始的m长度子串等于t
		if (s.substr(i, m) == t.substr(1)) {
			pa[i] = 1; // 标记这个位置匹配
		}
	}

	// 构造前缀和数组
	for (int i = 1; i <= n; ++i) {
		pa[i] += pa[i-1]; 
		cout << pa[i];
	}
	cout <<endl;

	// 处理查询
	ll l, r;
	for (int i = 0; i < q; i++) {
		cin >> l >> r;
		// 如果r-l+1小于m，说明t不可能出现在这个区间内
		if (r - l + 1 < m) {
			cout << 0 << endl;
		} else {
			cout << pa[r - m + 1] - pa[l - 1] << endl;
		}
	}
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ = 1;
	while (_--) solve();

	return 0;
}
