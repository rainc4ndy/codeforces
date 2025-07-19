#include <bits/stdc++.h> 
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
	vector<vector<int>> graph(n+1, vector<int>());
	vector<int> cnt(n+1);

	int x,y;
	for (int i = 1; i <= n - 1; i++) {
		cin >> x >> y;
		graph[x].push_back(y), graph[y].push_back(x);
		cnt[x]++, cnt[y]++;
	}
	for (int i = 1; i <= n; i++) {
		if (cnt[i] >= 3) {
			cout << -1 << endl;
			return;
		}
	}
	set<int> ans;
	for (int i = 1; i <= n; i++) { 
		if (cnt[i] == 1) {
			ans.insert(i);
			if (ans.size() == 2) {
				for (auto it : ans) {
					cout << it << ' ';
				}
				cout << endl;
				return;
			}
		} 
	}
	cout << -1 << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ = 1;
	while(_--) solve();

	return 0;
}