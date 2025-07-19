#include<bits/stdc++.h>

#define ll long long
#define ref(i,n) for(int i=0;i<n;i++)
#define ref1(i,n) for(int i=0;i<n;i++)
const int N = 2e4+10;
const ll inf = 9e18;
using namespace std;
ll a[N];
ll ans;
ll n;
ll k;
ll l,r;
ll temp;
int main()
{
    ll t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        ref(i,n){
            cin >> a[i];
        }
        sort(a,a+n);

        if(k > 2){
            cout << "0"<<endl;
            continue;
        }

        if(k == 1){
            ans = inf;
            ref1(i,n){
                ans = min(ans,a[i]);
                for(int j = i+1;j<n;j++){
                    ans = min(ans,abs(a[j]-a[i]));
                }
            }
        }

        if(k == 2){
            ans = inf;
            sort(a,a+n);
            ref(i,n){
                ans = min(ans,a[i]);
                for(int j = i+1;j<n;j++){
                    temp = a[j]-a[i];
                    ans = min(ans,temp);
                    l = 0;r = n;
                    while(l < r){
                        ll mid = l + (r-l)/2;
                        ans = min(ans,abs(a[mid]-temp));
                        if(a[mid] >= temp){
                            r = mid-1;
                        }
                        else{
                            l = mid+1;
                        }
                    }
                }
            }
        }
        cout << ans <<endl;
    }


    return 0;
}