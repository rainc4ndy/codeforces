#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
#define YES cout<<"YES\n"
#define NO  cout<<"NO\n"

int main(){
    fastio;
    int q;
    cin >> q;

    priority_queue<pll, vector<pll>, greater<pll>> p_minR;
    priority_queue<pll>                         p_maxL;
    map<pii,int> u;

    while(q--){
        char op;
        ll l, r;
        cin >> op >> l >> r;
        pii seg = { (int)l, (int)r };

        if(op == '+'){
            if(u[seg]++ == 0){
                p_minR.emplace(r, l);
                p_maxL.emplace(l, r);
            }
        }
        else {
            if(--u[seg] == 0)
                u.erase(seg);
        }

        while(!p_minR.empty()){
            auto [rr, ll_] = p_minR.top();
            if(u.find({ (int)ll_, (int)rr }) == u.end())
                p_minR.pop();
            else
                break;
        }
        while(!p_maxL.empty()){
            auto [ll_, rr] = p_maxL.top();
            if(u.find({ (int)ll_, (int)rr }) == u.end())
                p_maxL.pop();
            else
                break;
        }

        if(u.size() < 2){
            NO;
            continue;
        }

        auto [r_min, l_of_min] = p_minR.top();
        auto [l_max, r_of_max] = p_maxL.top();

        if(l_max > r_min) YES;
        else          NO;
    }

    return 0;
}
