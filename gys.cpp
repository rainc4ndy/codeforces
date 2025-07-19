// 请使用C++进行编程
#include <iostream>
#include <algorithm>
#define mod (110)

int main () {
    
    using namespace std;
    int n;
    cin >> n;

    int d[mod] {};
    int m = 1, t, ans = 1;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        flag = false;
        for (int j = d[i] - 1; j >= 1; j--) {
            if (d[i] % j == 0) {
                for (int k = 0; k < n; k++) {
                    if (k == i)
                        continue;
                    if (d[k] % j == 0) {
                        flag = true;
                    } else {
                        break;
                    }
                    ans = max(ans, j);
                }
                if (flag)
                    break;
            }
        }
    }
    cout << ans;

    return 0;
}