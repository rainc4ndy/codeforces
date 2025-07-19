#include <bits/stdc++.h> 
#include <vector>
using namespace std;

#define mod (500001)
#define ll long long
#define x first
#define y second
typedef pair<int, int> P;

int v[mod] {};
int n,m;
int lowbit(int x) {
	return x & (-x);
}

void add(int x, int value) {
	while (x <= n) {
		v[x] += value;
		x += lowbit(x); 
	}
}

int query(int x) {
	int sum = 0;
	while (x) {
		sum += v[x];
		x -= lowbit(x);
	}
	return sum;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	cin >> n >> m;
	int tmp;

	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		add(i, tmp);
	}

	vector<int> ans;

	int x, y, z;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y >> z;
		if (x == 1) {
			add(y, z);
		} else {
			ans.push_back(query(z) - query(y-1));
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		if (i != ans.size()-1)
			cout << endl;
	}
	return 0;
}