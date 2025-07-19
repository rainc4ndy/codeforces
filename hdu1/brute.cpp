#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	//code
}
bool flag[10000000] {};
int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 


    cout << "started" << endl;
    for (int i = 1; i <= 1000; i++) {
    	flag[i*i] = true;
    }


    for (int i = 0; i < 300000; i++) {
    	ll ss = i * (i + 1) / 2; 
		if (flag[ss]) {
			cout << i << endl;
			cout << "sum = " << ss << endl;
		}
    }
	


	return 0;
}