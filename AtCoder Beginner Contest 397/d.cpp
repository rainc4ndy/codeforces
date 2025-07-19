#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;
int main(){
    ll N;
    cin >> N;

    bool found = false;
    ll ans_x = 0, ans_y = 0;
    ll max_d = cbrt(4.0 * N);
    
    for (ll d = 1; d <= max_d; d++){
        if (N % d != 0) continue;
        
        ll temp = N / d;
        ll delta = 12 * temp - 3 * d * d;
        if (delta < 0) continue;
        
        ll S = (ll) sqrt((long double)delta);
        if (S * S != delta) continue;
        
        if ((S - 3 * d) % 6 != 0) continue;
        ll y0 = (S - 3 * d) / 6;
        if (y0 <= 0) continue;
        
        ll x0 = y0 + d;
        if (x0*x0*x0 - y0*y0*y0 == N){
            cout << x0 << " " << y0;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << -1;
    }
    
    return 0;
}
