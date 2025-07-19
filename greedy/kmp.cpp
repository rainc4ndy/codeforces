#include <bits/stdc++.h> 
using namespace std;

vector<int> buildPrefix(const string &pattern) {
    int m = pattern.length(), j = 0;
    vector<int> pi(m, 0);
    for (int i = 1; i < m; ++i) {
        while (j > 0 && pattern[i] != pattern[j])
            j = pi[j - 1];
        if (pattern[i] == pattern[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void KMP(const string &text, const string &pattern) {
    vector<int> pi = buildPrefix(pattern);
    int n = text.length(),
        m = pattern.length(),
        j = 0;

    for (int i = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j])
            j = pi[j - 1];
        if (text[i] == pattern[j])
            j++;
        if (j == m) {
            cout << "string found at index " << i - m + 1 << endl;
            j = pi[j - 1]; // 继续查找
        }
    }
}

int main() {
    string text = "ABABDABABCABACDABABCABAB";
    string pattern = "ABABC";
    KMP(text, pattern);
    return 0;
}
