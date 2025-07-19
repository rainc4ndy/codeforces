//L1-088 静静的推荐

#include <bits/stdc++.h> 
 
using namespace std;

struct st {
	int s1, s2;
};

int main() {
    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	st tmp;
	
	vector<st> v;
	unordered_map<int, int> m;

	// k是批次，实际上也就是 n"出现相同"的最大次数
	int n, k, s;
	cin >> n >> k >> s;
	
	for (int i = 0; i < n; i++) {
		cin >> tmp.s1 >> tmp.s2;

		if (tmp.s1 < 175)
			continue;

		v.push_back(tmp);
	}	

	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		if (m[v[i].s1] < k) {
			m[v[i].s1]++;
			ans++;
		} else if (v[i].s2 >= s){
			ans++;
		}
	}

	cout << ans;
	return 0;
}