#include <bits/stdc++.h> 
using namespace std;

#define SZ 100001

vector<int> ch[SZ];
int mx = 0;
int ans[SZ];
int ans_len = 0;
int d = 0;

void dfs(int root, int r) {
/*	cout << "root = " << root << endl; 
	cout << "r = " << r << endl; 
	cout << "mx = " << mx << endl; */
	if (r > mx) {
		ans_len = 0;
		mx = r;
		ans[ans_len++] = root;
	} else if (r == mx) {
		ans[ans_len++] = root;
	}

	if (ch[root].size() == 0)
		return;

	for (int i = 0; i < ch[root].size(); i++) {
		dfs(ch[root][i], r+1);
	}
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int n;
	cin >> n;

	int p;
	int root = -1;
	for(unsigned i = 0; i < n; ++i) {
		cin >> p;
		if (p == -1)
			root = i+1;
		else {
			ch[p].push_back(i+1);
		}
	}

	dfs(root, 0);
	sort(ans, ans + ans_len);

	cout << mx + 1 << endl; //边数+1 = 辈分
	for (int i = 0; i < ans_len; i++) {
		cout << ans[i];
		if (i != ans_len-1)
			cout << ' ';
	}

	return 0;
}