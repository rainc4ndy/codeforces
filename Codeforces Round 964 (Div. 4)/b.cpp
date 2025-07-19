#include <iostream>

using namespace std;

int countSuneetWins(int a1, int a2, int b1, int b2) {
    int suneetWins = 0;

    int suneetRound1 = (a1 > b1) ? 1 : 0;
    int slavicRound1 = (a1 < b1) ? 1 : 0;
    int suneetRound2 = (a2 > b2) ? 1 : 0;
    int slavicRound2 = (a2 < b2) ? 1 : 0;
    if (suneetRound1 + suneetRound2 > slavicRound1 + slavicRound2) suneetWins++;

    suneetRound1 = (a1 > b2) ? 1 : 0;
    slavicRound1 = (a1 < b2) ? 1 : 0;
    suneetRound2 = (a2 > b1) ? 1 : 0;
    slavicRound2 = (a2 < b1) ? 1 : 0;
    if (suneetRound1 + suneetRound2 > slavicRound1 + slavicRound2) suneetWins++;

    suneetRound1 = (a2 > b1) ? 1 : 0;
    slavicRound1 = (a2 < b1) ? 1 : 0;
    suneetRound2 = (a1 > b2) ? 1 : 0;
    slavicRound2 = (a1 < b2) ? 1 : 0;
    if (suneetRound1 + suneetRound2 > slavicRound1 + slavicRound2) suneetWins++;

    suneetRound1 = (a2 > b2) ? 1 : 0;
    slavicRound1 = (a2 < b2) ? 1 : 0;
    suneetRound2 = (a1 > b1) ? 1 : 0;
    slavicRound2 = (a1 < b1) ? 1 : 0;
    if (suneetRound1 + suneetRound2 > slavicRound1 + slavicRound2) suneetWins++;

    return suneetWins;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        
        cout << countSuneetWins(a1, a2, b1, b2) << endl;
    }

    return 0;
}
