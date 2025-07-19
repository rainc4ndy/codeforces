#include <bits/stdc++.h> 
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

int w[mod] {};
int lch[mod] {}, rch[mod] {};
int status[mod] {};

int get(int root) {
    if (!root) 
        return 0;
    
    return 1 + get(lch[root]) + get(rch[root]);
}

int ans = 1;
bool is_sym(int root) {
	if (status[root]) {
		return status[root] == 1;
	}

	if (!root)
		return true;

	if (!lch[root] && !rch[root]) {
		status[root] = 1;
		return true;
	}

	if (!lch[root] || !rch[root]) {
		status[root] = 2;
		return false;
	}

	if (w[lch[root]] != w[rch[root]]) {
		status[root] = 2;
		return false;
	}

	bool a = is_sym(lch[root]);
	bool b = is_sym(rch[root]);

	if (a && b) {
		status[root] = 1;
		ans = max(ans, get(root));
	} else {
		status[root] = 2;
	}
	return a && b;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int n;
    cin >> n;
   	for (int i = 1; i <= n; i++) {
   		cin >> w[i];
   	}

   	int x, y;
   	for (int i = 1; i <= n; i++) {
   		cin >> x >> y;
   		lch[i] = x == -1 ? 0 : x, rch[i] = y == -1 ? 0 : y;
   	}

	for (int i = 1; i <= n; i++) {
		is_sym(i);
   	}

   	cout << ans;
	return 0;
}