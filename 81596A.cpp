#include <bits/stdc++.h> 
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

long long binpow(long long a, long long b, long long p) {
    if (b == 0) return 1;
    long long res = binpow(a, b / 2, p);
    res = (res * res) % p; //先取模一次，防止溢出
    if (b % 2) {
        res = (res * a) % p;
    }
    return res;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    ll n,m,q;
    cin >> n >> m >> q;
 
 	ll tot = binpow(2,m, q);
    cout << binpow((tot+1)/2, n, q);

	return 0;
}