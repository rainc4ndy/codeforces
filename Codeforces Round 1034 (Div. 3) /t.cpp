#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;

void init_code(){
    #ifndef ONLINE_JUDGE
    //freopen("Error.txt", "w", stderr);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
//#define mod 998244353
# define mod  1000000007
#define nl "\n" 
#define precise(n) cout << fixed << setprecision(n)
#define popcnt(n) __builtin_popcountll(n)
#define int  long long
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define sz(v)   ((int)(v).size())
using vi = vector<int>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vvi = vector<vi>;
using vvpii = vector<vpii>;
using sti = set<int>;
using mpii = map<int, int>;
//------------
#define ff first
#define ss second
typedef unsigned long long ull;
typedef long double lld;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

//void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
//------------
#define fr(i, a, b) for (int i = a; i < b; i++)
#define fer(i, a, b) for (int i = a; i <= b; i++)
#define frr(i, a, b) for (int i = a; i >= b; i--)
void printDivisors(int n,set<int>&st); 
long long binpow(long long a, long long b, long long m);
void vecin(int n,vector<int>&v)   {for(int i=0;i<n;i++) cin>>v[i];}//0 based
void vecin1(int n,vector<int>&v)   {for(int i=1;i<=n;i++) cin>>v[i];}//1 based
#define mem(dp, x) memset(dp, x, sizeof dp)


vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void solve(){
      string s;cin>>s;
      vi z=z_function(s);
      int n=s.size();
      int flag=1;
      for(int i=0;i<n;i++){
            if(i<z[i]&&z[i]==(n-i)){
                cout<<"YES"<<endl;
                for(int j=i;j<n;j++) cout<<s[j];
                flag=0;
                break;
            }
      }
      if(flag) cout<<"NO"<<nl;
    




}

signed main(){
     init_code();

    int t;
    // cin>>t;
    t=1;
    while(t--){
        solve();
    }
 return 0;
} 



void printDivisors(int n,set<int>&st) 
{ 
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            if (n/i == i)   st.insert(i);
            else st.insert(i),st.insert(n/i);
        } 
    } 
}
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}