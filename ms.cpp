#include <bits/stdc++.h> 
#include <cstdio>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	int x = 32;
	int y = 64;
	printf("x + y = %d\n", x + y);

	int k = 3.1415926f;
	printf("k + 32.0 = %d\n", k + 32.0);

	int n = 2147483647;
	printf("n + 2147483647 = %d\n", n + 2147483647);
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