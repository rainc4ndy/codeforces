#include <algorithm>
#include <bits/stdc++.h> 
#include <cstdint>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

int v[111][111];

void solve() {
	int n,k;
	cin >> n >> k;

	int p1,p2,p3,p4;
	int mx = 0;
	vector<int> pa(128), ar(128);

	for (int i = 0; i < n; i++) {
		cin >> p1 >> p2 >> p3 >> p4;

		p1++, p2++, p3++, p4++;

		pa[min(p1,p3)]++;
		pa[max(p1,p3)+1]--;
		mx = max(mx, p1);
		mx = max(mx, p3);
	}

	for (int i = 1; i < 128; i++) {
		ar[i] = ar[i-1] + pa[i];
	}

	int ans = 0;
	vector<P> de;
	for (int i = 1; i <= mx; i++) {
		cout << ar[i] << ' ';
		if (ar[i] > k) {
			//remove ar[i] - k walls
			de.emplace_back(i, ar[i] - k);
		}
	}
	cout << ans << endl;
	//cout << ' '<< mx;
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