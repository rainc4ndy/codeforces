#include <bits/stdc++.h> 
#include <functional>
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

int v[mod] {};

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int n;
	cin >> n;

	for (int i = 0;i<n;i++) {
		cin >> v[i];
	}
	sort(v, v+n);
	int ans = 1;
	v[n-1]++;

	for (int i = n-2; i >=0; i--) {
		if (v[i]+1 != v[i+1]) {
			ans++;
			v[i]++;
		} else if (i > 1 && v[i]-1 != v[i-1]) {
			ans++;
			v[i]--;
		}
	}

	for (int i = 0;i<n;i++) {
		cout << v[i] << ' ';
	} cout << endl;

	cout << ans;

	return 0;
}