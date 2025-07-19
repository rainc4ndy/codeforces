#include <bits/stdc++.h> 
#include <vector>
using namespace std;

#define mod (100001)
#define ll long long
#define x first
#define y second
typedef pair<int, int> P;

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int t;
    cin >> t;
	int x, y;

	vector<P> ans(t);

    for (int i = 0; i < t; i++) {
		cin >> x >> y;

		ans[i] = {min(x, y), max(x, y)};
	}


	for (int i = 0; i < t; i++) {
		cout << ans[i].x << ' ' << ans[i].y;
		if (i != t-1)
			cout << endl;
	}


	return 0;
}