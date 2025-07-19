#include <bits/stdc++.h> 
#include <vector>
using namespace std;

#define mod (55)
#define ll long long
#define x first
#define y second
typedef pair<int, int> P;

int v[mod] {};
bool f[mod] {};
int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int t, n;
	cin >> t;
	vector<int> ans(t);
	for (int i = 0; i < t; i++) {
		cin >> n;

		for (int j = 1; j <= n; j++) {
			cin >> v[j];
			f[j] = false;
		}

		int mi = 0x3f3f3f3f;
		int step = 1;
		for (int j = 1; j <= n; j++) {

			step = 1;
			int trg = v[j];
			while (v[trg] != j) {
				step++;
				trg = v[trg];
			}
			cout << "step = " << step << endl;
			mi = min(mi, step);
		}
		ans[i] = mi;
	}


	for (int i = 0; i < t; i++) {
		cout << ans[i];
		if (i != t-1)
			cout << endl;
	}

	return 0;
}