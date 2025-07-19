#include <bits/stdc++.h> 
using namespace std;

const int SZ = 100000;

int lch[SZ] {}, rch[SZ] {};

int dfs(int root, int len) {
	if (!root)
		return len;

	return max(dfs(lch[root], len+1), dfs(rch[root], len+1));
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int n; 
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> lch[i] >> rch[i];
	}

	cout << dfs(1, 0);

	return 0;
}