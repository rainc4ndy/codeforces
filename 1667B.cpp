#include <bits/stdc++.h> 
using namespace std;

const int mod = 5e5+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

int v[mod] {};
int a[mod] {};
int dp[mod] {}; //前i个数字中， 可以获取的最大价值

int n;

int lowbit(int x) {
	return x & (-x);
}

int getsum(int x) {
	int ans = 0;
	while (x > 0) {
		ans += a[x];
		x -= lowbit(x);
	}
	return ans;
}

void add(int x, int k) {
	while (x <= n) {
		a[x] = a[x] + k;
		x += lowbit(x);
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < )
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int t;
	cin >> t;
	while(t--) {
	   	solve();
	}

	return 0;
}