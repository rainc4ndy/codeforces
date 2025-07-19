#include <bits/stdc++.h> 

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int n, M;
	cin >> n;

	vector<vector<long long>> v(n);
	long long num;

	for (int i = 0; i < n; i++) {
		cin >> M;
		for (int j = 0; j < M; j++)  {
			cin >> num;
			v[i].push_back(num);
		}
	}

	int pa, pb, k;
	cin >> k;

	vector<float> ans(k);
	cout.precision(2);

	unordered_map<long long, int> m;
	for (int i = 0; i < k; i++) {
		m.clear();

		cin >> pa >> pb;
		pa--;
		pb--;

		int nc = 0;

		for (int j = 0; j < v[pa].size(); j++) {
			m[v[pa][j]] = 1;
		}
		for (int j = 0; j < v[pb].size(); j++) {
			if (m[v[pb][j]] == 1) {
				m[v[pb][j]] = 3; //标记为在两个集合出现过两次
				nc++;
			} else if (m[v[pb][j]] == 0) { //在集合2出现过0次
				m[v[pb][j]] = 2;
			}
		}

		ans[i] = ((float)nc / (float)m.size()) * 100.f;
	}

	for (int i = 0; i < k; i++) {
		cout << fixed << ans[i] << '%';
		if (i != k - 1)
			cout << endl;
	}

	return 0;
}