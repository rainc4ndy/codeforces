#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int l, r;
        cin >> l >> r;
        
        int odd_count = (r + 1) / 2 - l / 2;
        
        
        cout << odd_count / 2 << endl;
    }
    
    return 0;
}
