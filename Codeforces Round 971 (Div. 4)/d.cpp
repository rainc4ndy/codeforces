#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int t;
    cin >> t;  

    while (t--) {
        int n;
        cin >> n; 

        vector<pair<int, int>> points(n);
        map<int, int> x_count, y_count;

        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            points[i] = {x, y};
            x_count[x]++;
            y_count[y]++;
        }

        long long right_triangles = 0;

        for (int i = 0; i < n; ++i) {
            int x = points[i].first;
            int y = points[i].second;
            right_triangles += (x_count[x] - 1) * (y_count[y] - 1);
        }

        for (int i = 0; i < n; ++i) {
        	int mid = 

        }

        cout << right_triangles << endl;
    }

    return 0;
}
