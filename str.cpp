// 请使用C++进行编程
#include <iostream>
#include <string>
int main () {
    using namespace std;

    string s, g;
    cin >> s >> g;
    
    int i = 0, c = 0;
    int h = 0;
    bool check = false;
    for (int i = 0; i < g.length(); i++) {
        if (!check) {
            if (g[i] == s[0]) {
                check = true;
                h = 1;
            }
        } else {
            if (g[i] != s[h]) {
                check = false;
                h = 0;
                continue;
            }
            if (h == g.length()) {
                check = false;
                c++;
                h = 0;
            }
            h++;
        }
    } 
    cout << c;

    return 0;
}