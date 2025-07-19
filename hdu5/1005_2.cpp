#include <bits/stdc++.h> 
#include <iomanip>
using namespace std;

#define rep(n) for (int _i_i_ = (n); _i_i_; --_i_i_)
#define mem(arr, x) memset((arr), x, sizeof (arr))
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define random rnd(chrono::system_clock::now().time_since_epoch().count())
#define setdb(v) setprecision(v)
#define debug(x) cout << #x << ' ' << x << endl;
#define x first
#define y second
#define YES cout << "YES\n"
#define Yes cout << "Yes\n"
#define NO cout << "NO\n"
#define No cout << "No\n"
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5+10;
const ll mod = 998244353;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        ll p;
        int n, k;
        cin >> p >> n >> k;
        
        vector<int> dis;      
        vector<ll> vad;  
        
        for (int i = 0; i < n; i++){
            int t, x;
            cin >> t >> x;
            if(t == 0){
                dis.push_back(x);
            } else {
                vad.push_back(x);
            }
        }
        
        sort(dis.begin(), dis.end());
        sort(vad.begin(), vad.end(), greater<ll>());
        
        int dsize = dis.size();
        vector<double> p1(dsize + 1, 1.0);
        for (int i = 1; i <= dsize; i++){
            p1[i] = p1[i - 1] * (dis[i - 1] / 10.0);
        }
        
        int rsize = vad.size();
        vector<ll> p2(rsize + 1, 0);
        for (int i = 1; i <= rsize; i++){
            p2[i] = p2[i - 1] + vad[i - 1];
        }
        
        double ans = p; 
        int mx = min(k, dsize);
        for (int i = 0; i <= mx; i++){
            int j = min(k - i, rsize);
            double cost = p * p1[i] - p2[j];
            ans = min(ans, cost);
        }
        if(ans < 0) ans = 0;
        
        cout << fixed << setprecision(2) << ans << "\n";
    }
    return 0;
}
