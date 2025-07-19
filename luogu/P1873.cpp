#include <bits/stdc++.h> 
#include <vector>
using namespace std;

#define ll long long 

ll n, m;
vector<ll> v;

bool f(ll M) {
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] > M)
			sum += v[i] - M;
	}
	//cout << "sum = " << sum << endl;
	return m <= sum;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	cin >> n >> m;
 	v.resize(n);

	ll l = 0, r = 0, mid;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		r = max(r, v[i]);
	}
	
	int ans = 0;

	while (l <= r) {
		mid = (l+r)/2;
		if (f(mid)) { //满足条件，从这个高度砍的木头够
			l = (ans=mid) + 1; //右查，提高H，向目标m的木头靠近
		} else {
			r = mid - 1; //左查，缩小H
		}
	}
	cout << ans;

	return 0;
}