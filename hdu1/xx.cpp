#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> A(n), B(n);
        vector<ll> C(n);
        for (int i = 0; i < n; ++i) cin >> A[i];
        for (int i = 0; i < n; ++i) cin >> B[i];
        for (int i = 0; i < n; ++i) cin >> C[i];
        
        ll sumA = accumulate(A.begin(), A.end(), 0LL);
        ll sumB = accumulate(B.begin(), B.end(), 0LL);
        ll sumC = accumulate(C.begin(), C.end(), 0LL);
        
        ll x = (sumC - sumB) / sumA;
        cout << x << '\n';
    }
    return 0;
}