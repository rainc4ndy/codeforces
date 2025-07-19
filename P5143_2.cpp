#include <bits/stdc++.h>
#include <memory>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

struct Point {
    double x, y, z, k;
};

// z1 == z2 (k)

bool cmp(Point& a, Point& b) {
    if (a.z == b.z) {
        return a.k < b.k;
    }
    return a.z < b.z;
}

void solve() {
    int n;
    cin >> n;
    vector<Point> points;
    points.push_back({x,y,z});
    points.emplace_back(x,y,z)

    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y >> points[i].z;

    sort(begin(points), end(points), cmp);

    double ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += sqrt(
            (points[i].x - points[i+1].x) * (points[i].x - points[i+1].x) +
            (points[i].y - points[i+1].y) * (points[i].y - points[i+1].y) +
            (points[i].z - points[i+1].z) * (points[i].z - points[i+1].z)
        );
    }

    cout << setprecision(3) << fixed << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int _ = 1;
    while (_) solve();

    return 0;
}
