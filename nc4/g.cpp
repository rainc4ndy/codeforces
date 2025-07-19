#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long xG, yG, xT, yT;
        cin >> xG >> yG >> xT >> yT;
        
        double distance1 = abs(yG) + sqrt((xG - xT) * (xG - xT) + yT * yT);
        double distance2 = abs(xG) + sqrt(xT * xT + (yG - yT) * (yG - yT));
        
        double r = min(distance1, distance2);
        cout << fixed << setprecision(10) << r << endl;
    }
    
    return 0;
}
