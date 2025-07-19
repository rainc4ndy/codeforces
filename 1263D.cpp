#include <bits/stdc++.h> 
#include <vector>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

int pa[mod];

int find(int x) {
	return x == pa[x] ? x : (pa[x] = find(pa[x]));
}

void unite(int x, int y) {
	pa[find(x)] = find(y);
}

string s[mod];
vector<int> cnt[256];

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int n;
    cin >> n;

	for (int i = 0; i<n;i++) {
		pa[i] = i;
		cin >> s[i];

		for (auto &it : s[i]) {
			cnt[(int)it].push_back(i);
		}
	}

	for (int i = 'a'; i <= 'z'; i++) {
		if (cnt[i].size() >= 2) {
			int e = cnt[i][0];
			for (int j = 1; j < cnt[i].size(); j++) {
				unite(e, cnt[i][j]);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (pa[i] == i) ans++;
	}

	cout << ans;

	return 0;
}