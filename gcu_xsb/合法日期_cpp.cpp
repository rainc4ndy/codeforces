#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
    int m, d;
    cin >> m >> d;
    int v[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m >= 1 && m <= 12 && d >= 1 && d <= v[m]) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int _ = 1;
    while(_--) solve();

    return 0;
}
