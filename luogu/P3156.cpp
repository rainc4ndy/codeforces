#include <bits/stdc++.h> 
#include <vector>
using namespace std;

#define mod (2000001)
#define ll long long
#define x first
#define y second
typedef pair<int, int> P;

ll v[mod] {};
ll ans[mod] {};

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int n,m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		ans[i] = v[num-1];
	}

	for (int i = 0; i < m; i++)
	{
		cout << ans[i];
		if (i != m-1)
			cout << endl;
	}
 
	return 0;
}