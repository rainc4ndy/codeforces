#include <bits/stdc++.h> 
#include <vector>
using namespace std;

const int mod = 2e6+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

int diff[mod] {};
int arr[mod] {};
int pa[mod] {};

void solve() {
	int n, k, q;
	cin >> n >> k >> q;

	vector<P> v(n);
	for (int i = 0; i < n; i++) cin >> v[i].x >> v[i].y;
	vector<P> d(q);
	for (int i = 0; i < q; i++) cin >> d[i].x >> d[i].y;


	for (int i = 0; i < n; i++) {
		diff[v[i].x] += 1;
		diff[v[i].y + 1] -= 1;
	}
	for (int i = 1; i < mod; i++) {
		arr[i] = arr[i-1] + diff[i];
	}

	for (int i = 1; i < mod; i++) {
		pa[i] = pa[i-1] + (arr[i] >= k);
	}

	for (int i = 0; i < q; i++) {
		cout << pa[d[i].y] - pa[d[i].x-1] << endl;
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