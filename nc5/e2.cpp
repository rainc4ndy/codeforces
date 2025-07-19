#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        
        // Sort both arrays
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int may_survivors = 0, i = 0, j = 0;

        // Simulate the duel
        while (i < n && j < n) {
            if (a[i] <= b[j]) {
                // May's knight is defeated
                i++;
            } else {
                // Ray's knight is defeated
                j++;
                may_survivors++;
            }
        }

        cout << may_survivors << endl;
    }
    
    return 0;
}
