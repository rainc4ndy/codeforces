#include <iostream>
#include <algorithm> // for std::gcd

using namespace std;

int number_of_pieces(int n, int k) {
    int gcd_nk = std::__gcd(n, k);
    // Correct formula
    int pieces = (n * n - n * gcd_nk) / 2 + 1;
    return pieces;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << number_of_pieces(n, k) << endl;
    return 0;
}
