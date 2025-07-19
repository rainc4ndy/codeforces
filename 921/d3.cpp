#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n, d, k;
        cin >> n >> d >> k;

        vector<int> overlaps(n + 2, 0); // Use n + 2 to manage boundaries

        // Step 1: Fill the overlaps using the difference array technique
        for (int i = 0; i < k; ++i) {
            int l, r;
            cin >> l >> r;
            overlaps[l] += 1;
            overlaps[r + 1] -= 1;
        }

        // Step 2: Compute the prefix sum to get the actual overlap counts
        for (int i = 1; i <= n; ++i) {
            overlaps[i] += overlaps[i - 1];
        }

        // Step 3: Find the best start days for brother and mother
        int max_overlap = -1, min_overlap = INT_MAX;
        int best_brother_day = 1, best_mother_day = 1;

        for (int start = 1; start <= n - d + 1; ++start) {
            int end = start + d - 1;

            // Count total overlaps for the current segment
            int current_overlap = 0;
            for (int j = start; j <= end; ++j) {
                current_overlap += overlaps[j];
            }

            // Update best day for brother
            if (current_overlap > max_overlap) {
                max_overlap = current_overlap;
                best_brother_day = start;
            }

            // Update best day for mother
            if (current_overlap < min_overlap) {
                min_overlap = current_overlap;
                best_mother_day = start;
            } else if (current_overlap == min_overlap) {
                best_mother_day = min(best_mother_day, start);
            }
        }

        cout << best_brother_day << " " << best_mother_day << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
