#include <bits/stdc++.h>
#include <string>
using namespace std;

void gen_rle(string &v) {
    string d = "";
    int sz = v.size();
    int l = 0, r = 0;

    while (r < sz) {
        while (r < sz && v[l] == v[r]) {
            r++;
        }
        int cnt = r - l;
        d += to_string(cnt) + v[l]; 
        l = r;
    }

    v = d; 
}

void solve() {
    int n;
    cin >> n;

    string v = "1"; 

    for (int i = 1; i < n; i++) {
        gen_rle(v); 
    }
    
    cout << v;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int _ = 1;
    while(_--) solve();

    return 0;
}
