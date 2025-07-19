#include <bits/stdc++.h>
using namespace std;
long long m,n,a[510],f;
struct gggg{
	int t;
	int w;
}x[510];
bool cmp(gggg lx,gggg ly){
	if(lx.w==ly.w) return lx.t<ly.t;
	return lx.w>ly.w;
}
int main(){
	cin>>m;
	cin>>n;
	
	for(int i=1;i<=n;i++) 
		cin>>x[i].t;
	for(int i=1;i<=n;i++) 
		cin>>x[i].w;
    sort(x+1,x+n+1,cmp);
	for(int i=1;i<=n;i++){
		f=0;
		for(int j=x[i].t;j>=1;j--)
			if(a[j]==0){
				f=j;
				break;
			}
		if(f>0) a[f]=1;
		else m-=x[i].w;
	}
    cout<<m;//输出
	return 0;
}