#include <bits/stdc++.h> 
using namespace std;

const int SZ = 256;

int lch[SZ] {}, rch[SZ] {};

void dfs(int root) {
	if (!root)
		return;
	cout << (char)root;

	dfs(lch[root]);
	dfs(rch[root]);
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int n;
	cin >> n;

	char x, y, z;

	char root = 0;

	for (int i = 0; i <n; i++) {
		cin >> x >> y >> z;
		if (y!='*')
			lch[(int)x] = y;
		if (z!='*')
			rch[(int)x] = z;
		if (!root)
			root =x;
	}
	dfs(root);

	return 0;
}