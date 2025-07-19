#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t; 
    while (t--) {
        long long k;
        cin >> k; //
        
        if (k == 1) {
        	cout << "YES" << endl;
        	continue;
        }

        if (k % 4 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
