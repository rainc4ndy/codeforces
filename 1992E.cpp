#include <bits/stdc++.h> 
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {  
    int n;
    cin >> n;

    vector<P> ans;
    int val;
    int rep;

    int arr[3];
    char tmp[256] {};
    itoa(n, tmp, 10);
    int len = 0;

    while (tmp[len]) {
        arr[len] = tmp[len]-'0';
        len++;
    }

    for (int a = 1; a <= 10000; a++) {
        //对于B:  上界: a*len-1，下界: a*len-6 (在区间内最多不会超过6个字符)
        for (int b = max(1, len*a -5); b <= a*len; b++) {
            val = (n*a) - b; //具体值
            rep = (a*len - b); //目标的字符串有多长

            if (!val || !rep) {
                break;
            }

            int r = 0;
            for (int i = 0; i < rep; i++) {
                r = r * 10 + arr[i%len];
            }
            if (r == val) {
                ans.push_back({a, b});
            }
        }       
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].x << ' ' << ans[i].y << endl;
    }
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}