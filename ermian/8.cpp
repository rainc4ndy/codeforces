#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	long long n;
	cin >> n;

	long long ans = 0;
	while (n > 0) {
		if (n % 10 == 0) {
			n /= 10;
		} else {
			n--;
		}
		ans++;
	}
	cout << ans << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ = 1;
	while(_--) solve();

	return 0;
}