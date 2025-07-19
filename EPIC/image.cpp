#include <bits/stdc++.h> 
#include <vector>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

char v[600][600] {};

void solve() {
	int n,m;
	cin >> n >> m;

	int p1,p2,p3,p4;
	p1=p2=0x3f3f3f3f;
	p3=p4=0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> v[i][j];
			if (v[i][j] == 'x') {
				p1 = min(p1,i);
				p2 = min(p2,j);
				p3 = max(p3,i);
				p4 = max(p4,j);
			}
		}
		cin.ignore();
	}

	int x = p3 - p1 + 1, y = p4 - p2 +1;
	int g = __gcd(x, y);

	x /= g;
	y /= g;

	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			cout << 'x';
		}
		cout << endl;
	}
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _ = 1;
	while(_--) solve();

	return 0;
}