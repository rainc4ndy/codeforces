#include <bits/stdc++.h> 
using namespace std;

#define ll long long
//const ll mod = 1e6 + 1e6*50;
#define x first
#define y second
typedef pair<int, int> P;

map<int, int> s;
void solve() {
	int n,m,k,h; //m stairs, k diff, h for height
	cin >> n >> m >> k >> h;

	int va;
	s.clear();
	for (int i = 0; i < n; i++) {
		cin >> va;
		s[va]++;
	}

	int tmp;
	int cnt = 0;

	for (int i = 1; i < m; i++) {
		tmp = max(0, h - i*k);
		if (s.count(tmp)) {
			cnt += s[tmp];
		}
		tmp = h + i*k;
		if (s.count(tmp)) {
			cnt += s[tmp];
		}
	}

	cout << cnt << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int t;
    cin >> t;
    while (t--) {

    	solve();
    }

	return 0;
}