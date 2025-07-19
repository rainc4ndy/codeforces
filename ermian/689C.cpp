#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	ll m;
	cin >> m;

	ll l, r, mid, ans=-1;

	auto f=[&](int x) -> bool {

	};

	while (l <= r) {
		mid = (l+r)>>1;
		if(f(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}	
	cout <<ans;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ = 1;
	while(_--) solve();

	return 0;
}