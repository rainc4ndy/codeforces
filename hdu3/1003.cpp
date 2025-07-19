#include <bits/stdc++.h> 
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

int status[mod] {}, pos[mod] {}, pa[mod] {};
//status: 1 找到中间的0
//status: 2 找完了两个p，等待找q

void solve() {
	for (int i =0;i<mod;i++) {
		status[i] = pos[i] = pa[i] = 0;
	}

	ll n;
	cin >> n;
	vector<ll> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	set<P> pp;
	unordered_set<ll> um;
	for (int i = 0; i < n; i++) {
		if (v[i] == 0) {
			for (auto it : um) {
				if (status[it] == 0) {
					status[it] = 1;
				}
			}
			um.clear();
		} else {
			if (!status[v[i]])
				um.insert(v[i]);
			else if (status[v[i]] == 1) {
				status[v[i]] = 2;
				pos[v[i]] = i;
			}
		}
	}

	// 计算后缀和 - 不包含0的unique个数
	unordered_set<ll> cur;
	pa[n - 1] = 1;
	cur.insert(v[n - 1]);
	for (int i = n - 2; i >= 0; i--) {
	    if (v[i] == 0) {
	        pa[i] = pa[i + 1];
	        continue;
	    }
	    if (cur.count(v[i])) {
	        pa[i] = pa[i + 1];
	    } else {
	        cur.insert(v[i]);
	        pa[i] = pa[i + 1] + 1;
	    } 
	}


	//统计答案
	int ans = 0;
	for (int x = 0; x < mod; x++)  {
		if (status[x] == 2) {
			// cout << "x " << x << endl;
			// cout << "pos[x] = " << pos[x] << endl;
			// cout << "pa[n-i] " << pa[pos[x]+1] << endl;
			ans += pa[pos[x]+1];
		}
	}
	cout << ans << endl;
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