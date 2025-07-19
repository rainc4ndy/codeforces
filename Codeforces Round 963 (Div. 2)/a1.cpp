#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        int countA = 0, countB = 0, countC = 0, countD = 0, countQ = 0;
        
        for (char c : s) {
            if (c == 'A') countA++;
            else if (c == 'B') countB++;
            else if (c == 'C') countC++;
            else if (c == 'D') countD++;
            else if (c == '?') countQ++;
        }
        
        int maxA = min(countA, n);
        int maxB = min(countB, n);
        int maxC = min(countC, n);
        int maxD = min(countD, n);
        
        int totalCorrect = maxA + maxB + maxC + maxD;
        int remaining = 4 * n - totalCorrect; 
        
        if (remaining > countQ) {
            remaining = countQ;
        }
        
        totalCorrect += remaining;
        
        cout << totalCorrect << endl;
    }
    
    return 0;
}
