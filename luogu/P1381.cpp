#include <bits/stdc++.h> 
#include <unordered_map>
#include <vector>
using namespace std;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int n;
	string s;
	cin >> n;
	unordered_map<string, bool> um;
	for (int i = 0; i < n; i++) {
		cin >> s;
		um[s] = false;
	}

	int m;
	cin >> m;
	vector<string> v(m+1);

	for (int i = 1; i <= m; i++) {
		cin >> v[i];
	}

	unordered_map<string, int> cnt; //区间内，单词出现的次数

	int l = 1, r = 1;
	int ll = 0, rr = 0;
	int len = 0x3f3f3f3f; //记录区间最小长度
	int t = 1; //区间内单词
	while (l <= r) {
		if ()
	}

	return 0;
}