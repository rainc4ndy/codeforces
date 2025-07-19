#include <bits/stdc++.h>
using namespace std;

long long binpow(long long a, long long b) {
  if (b == 0) return 1;
  long long res = binpow(a, b / 2);
  if (b % 2)
    return res * res * a;
  else
    return res * res;
}

#define ll unsigned long long
ll fastpow(ll a, ll n) {
  ll r = 1;
  while (n != 0) {
    if (n & 1) {
      r = r * a;
    }
    a = a * a;
    n = n >> 1;
  }
  return r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cout << "fastpow(4, 16) = " << fastpow(2, 16) << endl;
  cout << "binpow(4, 16) = " << binpow(2, 16) << endl;

  cout << "fastpow(2, 62) = " << fastpow(2, 63) << endl;
  cout << "binpow(2, 62) = " << binpow(2, 63) << endl;

  return 0;
}
