#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, k;
        cin >> n >> k;
        long long ans = 0;
        if(n % 2 == 0){
            ans = (n + k - 2) / (k - 1); 
        } else {
            if(n == k) ans = 1;
            else {
                n -= k;
                ans = 1 + (n + k - 2) / (k - 1); 
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
