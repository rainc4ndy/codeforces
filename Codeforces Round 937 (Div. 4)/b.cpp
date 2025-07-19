#include <bits/stdc++.h>
using namespace std;

const int SZ = 256;
char m[SZ][SZ] {};

void f(int row, int col, char c) {
    m[row][col] = c;
    m[row+1][col] = c;
    m[row][col+1] = c;
    m[row+1][col+1] = c;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t;
    cin >> t;

    vector<int> v(t);
    for (int i = 0; i < t; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < t; i++) {
        int n = v[i];

        bool dot = false;
        for (int j = 0; j < n * 2; j += 2) {
            for (int k = 0; k < n * 2; k += 2) {
                f(j, k, dot ? '.' : '#');
                dot = !dot;
            }
            if (n % 2 == 0) { // For even n, toggle the starting dot for each row.
                dot = !dot;
            }
        }

        // Print the matrix for this test case
        for (int j = 0; j < n * 2; j++) {
            for (int k = 0; k < n * 2; k++) {
                cout << m[j][k];
            }
            // Only print endl if it's not the last line of the last test case
            if (j < n * 2 - 1 || i < t - 1) {
                cout << endl;
            }
        }
        
        // Clear the matrix to prepare for the next test case
        memset(m, 0, sizeof(m));
    }
    return 0;
}
