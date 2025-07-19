#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(long long n) {
    if(n < 2)
        return false;
    if(n == 2 || n == 3)
        return true;
    if(n % 2 == 0 || n % 3 == 0)
        return false;
    for(long long i = 5; i*i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  
    int t;
    cin >> t;
    
    while(t--){
        long long x;
        int k;
        cin >> x >> k;
        
        if(k == 1) {
            cout << (isPrime(x) ? "YES" : "NO") << "\n";
        }
        else {
            if(x == 1 && k == 2)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}
