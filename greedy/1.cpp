#include <bits/stdc++.h>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

int a[30005], b[30005];

void solve() {
    int n, v, x, y, s1 = 0, s2 = 0;
    cin >> n >> v;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        if (x == 1) a[s1++] = y;
        else b[s2++] = y; 
    }

    sort(a, a + s1, greater<int>());
    sort(b, b + s2, greater<int>());

    int c1 = 0, c2 = 0; // actual count
    if (s2 * 2 >= v) {
        c2 = v / 2;
        if (c2 * 2 < v) c1++;
    } else {
        c2 = s2; 
        c1 = v - c2 * 2;
    }

    while (c2 && c1 + 1 < s1) {
        if (a[c1] + a[c1 + 1] > b[c2 - 1]) { // compare the sum of two a[] vs b[]
            c1 += 2;
            c2 -= 1;
        } else {
            break;
        }
    }

    int ans = 0;
    for (int i = 0; i < c1; i++)  // sum values from a[0] to a[c1-1]
        ans += a[i];
    for (int i = 0; i < c2; i++)  // sum values from b[0] to b[c2-1]
        ans += b[i];

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve(); // Call the function directly

    return 0;
}
