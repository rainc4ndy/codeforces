#include <bits/stdc++.h> 
#include <cwchar>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	int n;
	cin >> n;

	vector<ll> v(n);
	for (int i =0;i<n;i++) {
		cin >> v[i];
	}	

	vector<ll> d(begin(v),end(v));
	sort(begin(d), end(d));

	map<ll,int> m; //存储id
	for (int i = 0; i < n; i++) {
		m[d[i]] = i; 
	}

	vector<vector<int>> graph(n, vector<int>());
	vector<int> deg(n); //记录入度
	for (int i = 0; i < n; i++) {
		if (m.count(d[i] * 2)) {
			graph[i].emplace_back(m[d[i]*2]);
			deg[m[d[i]*2]]++;
		}
		if (d[i] % 3 == 0 && m.count(d[i] / 3)) {
			graph[i].emplace_back(m[d[i]/3]);
			deg[m[d[i]/3]]++;
		}
	}

	// for (int i = 0; i < n; i++) {
	// 	cout << "for " << d[i] << endl;
	// 	for (auto it : graph[i]) {
	// 		cout << d[it] << ' ';
	// 	}
	// 	cout << endl;
	// }

	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (!deg[i]) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << d[cur] << ' ';

		for (auto it : graph[cur]) {
			deg[it]--;
			if (!deg[it]) {
				q.push(it);
			}
		}
	}
}


int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ = 1;
	while(_--) solve();

	return 0;
}