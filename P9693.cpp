#include <bits/stdc++.h> 
#include <vector>
using namespace std;

#define mod (500001)
#define ll long long
typedef pair<int, int> P;

vector<P> v;

bool cmp(P&a, P&b) {
	return a.second - a.first < b.second - b.first;
}

void f() {
	int n, m;
	cin >> n >> m;

	v.clear();
	int x = 0, y = 0;
	int ans = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.emplace_back(x, y);
		sum += y;
	}
	sort(v.begin(), v.end(), cmp);

	if (n*2-1 <= m) {
		//无邻的可以全部分完 
		ans += sum;
	}

	for (auto it : v) {
		if 
	}

	for (int i = 0; i < n; i++) {
		if (a[i] > b[i])
			ans += a[i]; 
	}

	cout << "ans = " <<  ans << endl;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int t;
	cin >> t;
	while (t--)
		f();

	return 0;
}