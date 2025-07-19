#include <bits/stdc++.h> 
#include <vector>
using namespace std;



#define mod (500005)
#define ll long long
#define x first
#define y second
typedef pair<int, int> P;

int a[mod] {};
int d[mod] {};
int n,m;
int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		d[i] = a[i] - a[i-1];
	}
 
	vector<int> ans;

	int x, y, z, k;
	for (int i = 1; i <= m; i++) {
		cin >> x;
		if (x == 1) {
			cin >> y >> z >> k;
			d[y] += k;
			d[z+1] -= k;

		} else {
			cin >> y;

			//恢复原数组
			a[0] = d[0];
			for (int i = 1; i<=n; i++) {
				a[i] = a[i-1] + d[i];
			}

			ans.push_back(a[y]);
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		if (i != ans.size()-1)
			cout << endl;
	}
	return 0;
}