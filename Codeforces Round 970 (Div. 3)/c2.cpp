#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long l, r;
        cin >> l >> r;
        
        // Calculate the maximum length of the "good array"
        long long diff = r - l;
        long long n = (long long)(sqrt(2 * diff + 0.25) - 0.5);
        
        cout << n + 1 << endl; // Include the first element in the array
    }
    
    return 0;
}
