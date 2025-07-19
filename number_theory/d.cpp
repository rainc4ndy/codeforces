#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

constexpr long long MOD = 1000000007;

struct Matrix {
    int n, m;
    vector<vector<long long>> data;
    
    Matrix(int n_, int m_) : n(n_), m(m_), data(n_, vector<long long>(m_, 0)) { }
    
    void initIdentity() {
        for (int i = 0; i < n; i++) {
            data[i][i] = 1;
        }
    }
};

Matrix multiply(const Matrix &A, const Matrix &B) {
    Matrix C(A.n, B.m);
    for (int i = 0; i < A.n; i++) {
        for (int k = 0; k < A.m; k++) {
            if (A.data[i][k] > 0) {
                for (int j = 0; j < B.m; j++) {
                    C.data[i][j] = (C.data[i][j] + (A.data[i][k] * B.data[k][j]) % MOD) % MOD;
                }
            }
        }
    }
    return C;
}

Matrix fastExponentiation(Matrix base, long long exp) {
    Matrix result(base.n, base.m);
    result.initIdentity();
    while(exp > 0) {
        if(exp & 1) {
            result = multiply(result, base);
        }
        base = multiply(base, base);
        exp >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--) {
        long long l, r, k;
        cin >> l >> r >> k;
        
        Matrix a(71, 71);
        for (int t = 0; t <= 6; t++) {
            for (int j = 0; j <= 9; j++) {
                for (int x = 0; x <= 9; x++) {
                    if (x + j != k) {
                        int from = j + 10 * t;
                        int modVal = (t * 10 + x) % 7;
                        int to = x + modVal * 10;
                        a.data[from][to] = 1;
                    }
                }
            }
        }
        for (int i = 0; i < 10; i++) {
            a.data[i][70] = 1;
        }
        a.data[70][70] = 1;
        
        Matrix a1 = a;
        Matrix b(1, 71);
        for (int j = 1; j <= 9; j++) {
            int modVal = j % 7;
            int idx = j + modVal * 10;
            b.data[0][idx] = 1;
        }
        
        Matrix b1 = b;  // copy of b
        
        Matrix ans = fastExponentiation(a, l - 1);
        Matrix cnt = multiply(b, ans);
        long long sum1 = cnt.data[0][70];
        
        Matrix ans1 = fastExponentiation(a1, r);
        Matrix cnt1 = multiply(b1, ans1);
        long long sum2 = cnt1.data[0][70];
        
        cout << ( (sum2 - sum1 + MOD) % MOD ) << "\n";
    }
    
    return 0;
}
