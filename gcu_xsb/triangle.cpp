#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

void solve() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
        int x = n - i; // 计算空格数量
        for (int j = 1; j <= x; j++) cout << ' '; // 打印左侧空格
        for (int k = 1; k <= (2 * i - 1); k++) cout << '*'; // 打印星号
        cout << endl; // 换行
    }	
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int _= 1;
	while(_--) solve();

	return 0;
}