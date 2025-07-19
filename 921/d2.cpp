#include <bits/stdc++.h>
using namespace std;

const int mod = 1e5 + 10;
typedef long long ll;

ll diff[mod];
ll arr[mod];

void solve() {
    ll n, d, k;
    cin >> n >> d >> k;

    memset(diff, 0, sizeof(diff));
    memset(arr, 0, sizeof(arr));

    int l, r;
    for (int i = 0; i < k; i++) {
        cin >> l >> r;
        diff[l] += 1;      
        diff[r + 1] -= 1;   
    }

    for (int i = 1; i <= n; i++) {
        arr[i] = arr[i - 1] + diff[i];
    }

    ll max_unique_overlap = LLONG_MIN;
    ll min_unique_overlap = LLONG_MAX; 
    ll max_index = -1, min_index = -1;

    for (int i = 1; i + d - 1 <= n; i++) {
        unordered_set<int> unique_count; // 存储当前区间的唯一重叠
        for (int j = i; j < i + d; j++) {
            unique_count.insert(arr[j]); // 记录唯一值
        }

        ll current_unique = unique_count.size();

        if (current_unique > max_unique_overlap) {
            max_unique_overlap = current_unique;
            max_index = i;
        }

        if (current_unique < min_unique_overlap) {
            min_unique_overlap = current_unique;
            min_index = i;
        }
    }

    cout << "Max Unique Overlap: " << max_unique_overlap << " at index " << max_index << endl;
    cout << "Min Unique Overlap: " << min_unique_overlap << " at index " << min_index << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
