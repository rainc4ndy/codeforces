#include <bits/stdc++.h> 
using namespace std;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int n; string s;
	cin >> n >> s;

	bool acc[128] {};
	int cnt = 0;
	for (auto it : s) {
		if (!acc[(int)it])
			cnt++;
		acc[(int)it] = true;
	}
	int ans = 0;
	int found = 0;
	for (auto it : s) {
		if (acc[(int)it]) {
			acc[(int)it] = false;
			found++;
		}
		if (found >= cnt)
			break;
		ans++;
	}

	cout << ans + 1;

	return 0;
}