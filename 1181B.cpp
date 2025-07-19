#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

// 高精度字符串加法
string add(const string &A, const string &B) {
    string a = A, b = B, res;
    int i = a.size()-1, j = b.size()-1, carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int x = i >= 0 ? a[i--] - '0' : 0;
        int y = j >= 0 ? b[j--] - '0' : 0;
        int s = x + y + carry;
        res.push_back(char('0' + s % 10));
        carry = s / 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

// 数值字符串比较：长度短的是小，长度相同按字典序
bool lessNum(const string &x, const string &y) {
    if (x.size() != y.size()) return x.size() < y.size();
    return x < y;
}

int main() {
    fastio;
    int n;
    string s;
    cin >> n >> s;
    int mid = n / 2;

    int i = mid;
    while (i >= 1 && s[i] == '0') --i;

    int j = mid + 1;
    while (j < n && s[j] == '0') ++j;

    string best = string(n + 5, '9');  // 一个非常大的“哨兵”值
    if (i >= 1) {
        string a = s.substr(0, i);
        string b = s.substr(i);
        best = add(a, b);
    }
    if (j < n) {
        string a = s.substr(0, j);
        string b = s.substr(j);
        string sum2 = add(a, b);
        if (lessNum(sum2, best)) best = sum2;
    }

    cout << best << "\n";
    return 0;
}
