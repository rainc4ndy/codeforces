#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;
    vector<int> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    // 统计频率
    unordered_map<int,int> cnt;
    cnt.reserve(n*2);
    for(int x: A) cnt[x]++;

    ll deletions = 0;
    if (d == 0) {
        for (auto &p : cnt) {
            deletions += p.second - 1;
        }
    } else {
        vector<int> keys;
        keys.reserve(cnt.size());
        for (auto &p : cnt) keys.push_back(p.first);
        sort(keys.begin(), keys.end());

        // 对每一个 x，看 x+d 是否还剩余冲突
        for (int x : keys) {
            int c1 = cnt[x];
            if (c1 <= 0) continue;              // 已经被“删光”了
            auto it = cnt.find(x + d);
            if (it == cnt.end()) continue;     // 没有冲突值
            int c2 = it->second;
            if (c2 <= 0) continue;             // 已经处理过
            // 两组之间删掉较小的一方
            int del = min(c1, c2);
            deletions += del;
            if (c1 < c2) {
                cnt[x] = 0;
                it->second = c2 - del;
            } else {
                cnt[x] = c1 - del;
                it->second = 0;
            }
        }
    }

    cout << deletions << "\n";
    return 0;
}

//那个可能比较少..我最近在准备下个月的icpc，，