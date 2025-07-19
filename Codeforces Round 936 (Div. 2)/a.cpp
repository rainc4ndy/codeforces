#include <algorithm>
#include <bits/stdc++.h> 
#include <utility>
#include <vector>
using namespace std;

//你的任务是找出增加数组中位数所需的最少操作次数。

#define ll long long

ll v[100000] {};

int n;

int bin(int start, int num) {
	int l = start, r = n, mid;
	int ans = -1;
	while(l<=r){
		mid=(l+r)>>1;
		if(v[mid] < num) l=(ans=mid)+1;
		else if (v[mid] > num) r=mid-1;
		else return mid;
	}
	return ans;
}

int f() {
	int mid = v[(n-1)/2];
	int m;
	int tmp = 0;
	int cnt = 0;
	while (v[(n-1)/2] == mid) {
		m = (n-1) / 2;

		v[m]++;
		cnt++;

		for (int i = m; i < n; i++) {
			if (v[i] == mid)
				cnt++;
		}
	}	
	return cnt;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int t;
	cin >> t;

	vector<int> ans(t);

	for (int i = 0; i < t; i++ ){
		cin >> n;

		for (int j = 0; j < n; j++) {
			cin >> v[j];
		}
		sort(v, v+n);


		ans[i] = f();
	}

	for (int i = 0; i < t; i++) {

		cout <<  ans[i] ;
		if (i != t-1)
			cout << endl;
	}
	return 0;
}