#include <bits/stdc++.h> 
using namespace std;

vector<int> v;

int cnt = 0;
int x, y;
int f(int l, int r) {
	if (abs(r-l) <= 1) {
		return max(v[r], v[l]);
	}

	int mid = (l+r) >> 1;
	x = f(l, mid);
	y = f(mid+1, r);
	

	return max(x, y);
}

int main() {    
    //ios_base::sync_with_stdio(false); 
    //cin.tie(NULL); 

	int n;
	cin >> n;
	v.resize(pow(2, n)+1);

	for (int i = 1; i < v.size(); i++) {
		cin >> v[i];
	}

	f(1, v.size()-1);
	cout << min(x, y);

	return 0;
}