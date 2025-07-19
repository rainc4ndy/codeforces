#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

ll v[mod], d[mod];

void solve() {
	ll n,q;
	cin >> n >> q;

	for (int i =0; i < n; i++)
		cin >> v[i];

	for (int i = 0;i<q;i++)
		cin >> d[i];

}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _;
	cin >> _;
	while(_--) solve();

	return 0;
}