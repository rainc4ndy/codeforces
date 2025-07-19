#include <bits/stdc++.h>
using namespace std;

void f(int step, vector<bool> &v) {
    int sz = v.size();
    int a = 0, b = 0;
    //直到分差大于或者等于2 才一局结束。
    for (unsigned i = 0; i < sz; ++i) {
        if (v[i])
            a++;
        else
            b++;
        if (i == sz - 1) {
            cout << a << ':' << b;
            if (a + b == step) {
                cout << endl;
                cout << 0 << ':' << 0;
            }
            break;
        }
        if (a >= step || b >= step) {
            if (abs(a - b) >= 2) {
                cout << a << ':' << b;

                if (i != sz - 1)
                    cout << endl;
                a = 0; b = 0;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<bool> v;

    char c;
    while (true) {
        cin >> c;
        if (c == '\n')
            continue;
        if (c == 'E')
            break;
        v.emplace_back(c == 'W');
    }

    if (v.size() == 0) {
        cout << "0:0" << endl << endl;
        cout << "0:0" << endl;
        return 0;
    }

    f(11, v);
    cout << endl << endl;
    f(21, v);
    cout << endl;

    return 0;
}
