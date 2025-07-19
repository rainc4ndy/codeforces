#include <bits/stdc++.h> 
using namespace std;

const int mod = 101;
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
	for (int i = 1; i <= n; i++) {
		cin >> v[i];		
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] == 0) {
			if (v[i+1] && v[i-1]) {
				v[i+1] = 0;
				ans++;
			}
		}
	}
	cout << ans;
 
	return 0;
}