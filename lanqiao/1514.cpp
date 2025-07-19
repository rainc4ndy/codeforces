#include <bits/stdc++.h> 
using namespace std;

typedef unsigned long long ll;

ll k;

ll binpow(ll a, ll b) {
	ll r = 1;
	while (b) {
		if (b % 2 == 1) {
			r = (r * a) % k;
		}
		a = (a * a) % k;
		b = b / 2;
	}

	return r;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int b,p;
	cin >> b >> p >> k;

	cout << binpow(b, p);

	return 0;
}