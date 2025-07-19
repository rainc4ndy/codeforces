#include <bits/stdc++.h> 
#include <functional>
#include <vector>
using namespace std;

#define mod (101)
#define ll long long
#define x first
#define y second
typedef pair<int, int> P;

int v[mod] {};
int cnt[300] {};

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int t;
	cin >> t;
	int n, k, l;
	vector<int> ans(t);
	for (int i = 0; i < t; i++) {
		cin >> n >> k;

		memset(cnt, 0, sizeof(cnt));
		for (int j = 0; j < n; j++) {
			cin >> v[j];
			cnt[v[j]]++;
		}

		sort(cnt, cnt + mod, std::greater<int>());

		l = n;
		
		int x = 0;
		for (;;) {
			//cout << "cnt[x] == " << cnt[x] << endl;
			//cout << "k == " << k << endl;
			if (cnt[x] == k) {
				cnt[x] = 0;
				if (cnt[x+1])
					cnt[x+1] += k-1;
				l--;
				x++;
			} else if (cnt[x] > k) {
				cnt[x]--;
				l--;
			}
			else break;
		}
		ans[i] = l;
	}

	for (int i = 0; i < t; i++) {
		cout << ans[i];
		if (i != t-1)
			cout << endl;
	}

	return 0;
}