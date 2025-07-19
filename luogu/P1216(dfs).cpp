#include <bits/stdc++.h> 
 
using namespace std;

vector<vector<int>> v;
int r;

int dfs(int row, int id) {

	if (row >= r - 1) {
		return v[row][id];
	}
	
	int a = dfs(row + 1, id) + v[row][id];
	int b = dfs(row + 1, id + 1) + v[row][id];

	return max(a, b);
}

int main() {

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    cin >> r;

    int num;

    for (int i = 0; i < r; i++) {
    	v.emplace_back(vector<int>());
    	for (int j = 0; j <= i; j++) {
    		cin >> num;
    		v[i].push_back(num);
    	}
    }

    int ans = dfs(0, 0);

    cout << ans;
	return 0;
}