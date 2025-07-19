#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 30001;

vector<int> arr(MAXN);
vector<ll> tree1(MAXN), tree2(MAXN);
int n, m = MAXN - 1;

inline int lowbit(int x) {
    return x & -x;
}

void add(vector<ll>& tree, int i, ll c) {
    while (i <= m) {
        tree[i] += c;
        i += lowbit(i);
    }
}

ll sum(const vector<ll>& tree, int i) {
    ll ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= lowbit(i);
    }
    return ans;
}

ll compute() {
    fill(tree1.begin(), tree1.end(), 0);
    fill(tree2.begin(), tree2.end(), 0);
    
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += sum(tree2, arr[i] - 1);
        add(tree1, arr[i], 1);
        add(tree2, arr[i], sum(tree1, arr[i] - 1));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    cout << compute() << "\n";
    return 0;
}
