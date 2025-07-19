#include <bits/stdc++.h> 
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

int ans = 0;
bool ok = false;
bool dfs(ll x, ll y) {
	if (x > y)
		return false;
	if (x == y) {
		ok = true;
		return true;	
	}
	if (dfs(x*2, y)) {
		ans++;
		return true;
	}
	else if (dfs(x*3, y)) {
		ans++;
		return true;
	}
	return false;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	ll x,y;
	cin >>x >> y;
	dfs(x, y);
	if (!ok)
		cout << -1;
	else 	
		cout << (ans);


	return 0;
}