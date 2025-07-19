#include <bits/stdc++.h> 
#include <vector>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	int n,d;
	cin >> n >> d;

	set<int> v = {1};

	if (d == 5) {
		v.insert(5);
	}
	if (n >= 3) {
		v.insert(3);
		v.insert(7);
	} 

	if (n <= 10) {
		int r =1;
		for (int i =1;i<=n;i++) r*=i;

		if (r * d % 3 == 0) v.insert(3);
		if (r * d % 9 == 0) v.insert(9);
	}
	if (n >= 6) { 
		//6的阶乘里面有两个3的因子

		//阶乘是9的倍数，9的倍数个相同的数字加起来的和可以整除9
		v.insert(9);
	}
	if (d == 7) {
		v.insert(7);
	}


	for (auto it : v) {
		cout << it << ' ';
	}

	cout << endl;
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