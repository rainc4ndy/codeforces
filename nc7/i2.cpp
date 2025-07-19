#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	ll l, x, y;
    cin >> l >> x >> y;

    double lSquared = (double)(l) * l;
    double ySquared = (double)(y) * y;
    
    if (lSquared < ySquared) {
        cout << "No" << endl;
        return;
    }
    
    double radius = sqrt(lSquared - ySquared);
    double pMin = x - radius;
    double pMax = x + radius;
    
    if (pMin < 0) pMin = 0;
    if (pMax > l) pMax = l;
    
    if (pMin <= pMax) {
        cout << "Yes" << endl;
        cout << setprecision(6) << pMin << endl;
    } else {
        cout << "No" << endl;
    }
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