#include <bits/stdc++.h> 
#include <vector>
using namespace std;

struct st {
	string s;
	int a, b, c;
};

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    st tmp, ans;
    int n;
    int mx = 0;
    cin >> n;
    vector<st> v;
    for (int i =0; i < n; i++) {
    	cin >> tmp.s >> tmp.a >> tmp.b >> tmp.c;
    	

    }
    sort(v.begin(), v.end(), f);
    cout << v[0].s << ' ' << v[0].a << ' ' << v[0].b << ' ' << v[0].c;
	//code

	return 0;
}