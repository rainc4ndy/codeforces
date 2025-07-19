#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    cin >> num;

    double sum = 0, t;
    for (int i = 0; i < num; i++) {
        cin >> t;
        sum += 1.0 / t;
    }

    cout << fixed << setprecision(2) << 1.0 / (sum / (double)num);

    return 0;
}
