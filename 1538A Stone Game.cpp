#include <bits/stdc++.h> 
#include <vector>
#include <algorithm>
  
int main() {
    using namespace std;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int n = 0;
	cin >> n;
	vector<vector<int>> v;

	for (int i = 0; i <= n; i++) {
		int k;
		cin >> k;
		vector<int> tmp;
		v.push_back(tmp);
		for (int j = 0; i < k; i++) {
			cin >> k;
			v[j].push_back(k);
		}
	}

	for (int i = 0; i <= n; i++) {
		int m_max = 0, m_min = 0;
		for (int j = 0; i < v[i].size(); i++) {
			m_max = max(v[i][j], m_max);
			m_min = min(v[i][j], m_min);
		}
	}

	return 0;
}