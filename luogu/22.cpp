#include <iostream>
#include <cmath>

using namespace std;

double f2(double x) {
    return 2*x*x*x - 4*x*x + 3*x - 6;
}

int main() {    
    double l = -100000, r = 100000;
    double mid, tol = 1e-9; // Tolerance

    while (r - l > tol) {
        mid = (l + r) / 2;
        if (f2(mid) == 0) {
            cout << "Root found at x = " << mid << endl;
            break;
        }
        if (f2(l) * f2(mid) < 0) {
            r = mid;
        } else {
            l = mid;
        }
    }

    if (fabs(f2(mid)) <= tol) {
        cout << "Root approximately at x = " << mid << endl;
    } else {
        cout << "No root found within the given tolerance." << endl;
    }

    return 0;
}
