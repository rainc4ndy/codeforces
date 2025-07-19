#include <bits/stdc++.h> 
#include <vector>
using namespace std;

#define mod (500005)
#define ll long long
#define x first
#define y second
typedef pair<int, int> P;

int a[mod] {};
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

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	vector<int> ans;

	int x, y, z, k;
	for (int i = 1; i <= m; i++) {
		cin >> x;
		if (x == 1) {
			cin >> y >> z >> k;
			add(y, k);
			add(z+1, -k);
		} else {
			cin >> y;
			ans.push_back(a[y]+query(y)); //差分数组做一次前缀和就得到了总影响
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		if (i != ans.size()-1)
			cout << endl;
	}
	return 0;
}