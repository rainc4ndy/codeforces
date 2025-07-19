#include <bits/stdc++.h> 
#include <vector>
using namespace std;

#define mod (100001)
#define ll long long
#define x first
#define y second
typedef pair<int, int> P;

int v[10000] {};

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int t;
	cin >> t;

	vector<int> ans(t);
	int y, n, y2;
	int r = 0;
	for (int i =0 ; i < t; i++) {
		cin >> y >> n;

		for (int j =0; j < n; j++) {
			cin >> v[j];
		}

		cin >> y2;
		r = y2 - y +1;

		for (int j= 0; j < n; j++) {
			if (v[j] >= y && v[j] <= y2)
				r--;
		}

		ans[i] = r;
	}

	for (int i = 0; i < t; i++) {
		cout << ans[i];
		if (i != t-1)
			cout << endl;
	}


	return 0;
}