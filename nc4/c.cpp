#include <bits/stdc++.h> 
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

int v[mod];
int d[mod]; //数字在未排序数组中的位置
void solve() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		d[v[i]] = i;
	}

	int p2 = 0; 

	for (int i = 1; i <= n; i++) {
		if (d[i] != i) {
			int l1 = d[i]; // l of 2
			int l2 = d[v[i]]; 

			d[v[l1]] = v[l1];
			d[v[l2]] = v[l2];
			swap(v[l1], v[l2]);
			p2 += 2;
		}
	}

	cout << ceil((float)(p2) / 4.f) << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}