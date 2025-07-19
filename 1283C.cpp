#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

int v[mod] {};
int in[mod] {}, out[mod] {};

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int n;
    cin >> n;

    for (int i = 1; i <=n;i++) {
        cin >> v[i];
        if (v[i]) {
            in[v[i]]++;
            out[i]++;
        } else {
            out[i] = 0;
        }
    }	

    set<P> s; //用堆的性质，优先把礼物给给没收到礼物，且没送出礼物的人
    for (int i = 1; i <=n;i++) {
        if (!in[i]) {
            s.insert({out[i], i});
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!v[i]) {
            auto it = s.begin();
            if ((*it).y == i) it++; //it++必然有效，如果s.size()==1则此行不执行

            v[i] = (*it).y; //i 给 (*it).y 送出礼物
            in[(*it).y]++;
            s.erase(it); //以后就不需要再给 (*it).y送礼物

            //如果送出礼物的这个人，他没收到过礼物，说明他可以继续收
            //这里特加判断，每个人只能送出一份礼物
            if (out[i] == 0 && in[i] == 0) {
                s.erase({out[i], i}); //更新 i 送出的礼物数量
                out[i]++;
                s.insert({out[i], i});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << v[i] << ' ';
    }

	return 0;
}