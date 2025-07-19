#include<bits/stdc++.h>
using namespace std;
int n,v,i,x,y,s1,s2,l,r,ans,fish1[30005],fish2[30005];
bool cmp(int k1,int k2){
    return k1>k2;
}
int main(){
    cin>>n>>v;
    for(i=1;i<=n;i++){
        cin>>x>>y;
        if(x==1) fish1[++s1]=y;
        else fish2[++s2]=y;
    }
    sort(fish1+1,fish1+1+s1,cmp);
    sort(fish2+1,fish2+1+s2,cmp);

    if(s2*2>=v){ //if we can't contain all w2 fishes
        r=v/2; //contain half
        if(r*2<v) l++;
    }
    else{
        // contain all w2, considering w1;
        r=s2;l=v-r*2;
    }
    while(l<=s1&&r){
        if(fish2[r]<fish1[l+1]+fish1[l+2]){
            r--;l+=2;
        }
        else break;
    }
    for(i=1;i<=l;i++) ans+=fish1[i];
    for(i=1;i<=r;i++) ans+=fish2[i];
    cout<<ans<<endl;
    return 0;
}