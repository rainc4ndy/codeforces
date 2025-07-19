#include <bits/stdc++.h> 
using namespace std;

#define mod (100001)
#define ll long long
#define x first
#define y second
typedef pair<int, int> P;

long long binpow(long long a, long long b, long long p) {
    if (b == 0) return 1;
    long long res = binpow(a, b / 2, p);
    res = (res * res) % p; 
    if (b % 2) {
        res = (res * a) % p;
    }
    return res;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	ll a, b, p;
	cin >> a >> b >> p;

	cout << a << '^' << b << " mod " << p << '=' << binpow(a, b, p);

	return 0;
}