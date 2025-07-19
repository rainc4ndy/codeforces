#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	ull n, coins = 1;
	cin >> n;

    while (n > 3) {
        n /= 4;  
        coins *= 2;
    }	

    cout << coins << endl;
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