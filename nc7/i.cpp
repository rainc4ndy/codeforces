#include <iostream>
#include <cmath>
#include <iomanip> // for std::setprecision

using namespace std;

void solveTestCase(int l, int x, int y) {
    double lSquared = static_cast<double>(l) * l;
    double ySquared = static_cast<double>(y) * y;
    
    if (lSquared < ySquared) {
        cout << "No" << endl;
        return;
    }
    
    double radius = sqrt(lSquared - ySquared);
    double pMin = x - radius;
    double pMax = x + radius;
    
    if (pMin < 0) pMin = 0;
    if (pMax > l) pMax = l;
    
    if (pMin <= pMax) {
        cout << "Yes" << endl;
        cout << fixed << setprecision(6) << pMin << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); // Faster I/O
    cin.tie(nullptr); // Untie cin and cout for faster I/O

    int T;
    cin >> T;
    
    while (T--) {
        int l, x, y;
        cin >> l >> x >> y;
        solveTestCase(l, x, y);
    }
    
    return 0;
}
