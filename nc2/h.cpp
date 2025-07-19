#include <bits/stdc++.h> 
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

char v[mod] {};

int px[mod] {};
int py[mod] {};

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int n,x,y;
	cin >> n >> x >> y;

	char c;
	for (int i = 1; i <= n; i++) {
		cin >> c;
		if (c == 'D')
			px[i] = px[i-1] + 1;
		else if (c == 'A')
			px[i] = px[i-1] - 1;
		else if (c == 'W')
			py[i] = py[i-1] + 1;
		else if (c == 'S')
			py[i] = py[i-1] - 1;
	}
	
	//如果x>0，至少要走x个D
	//如果y>0, zhishao y w



	return 0;
}