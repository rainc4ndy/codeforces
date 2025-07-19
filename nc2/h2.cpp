#include <bits/stdc++.h> 
#include <vector>
using namespace std;

const int mod = 2e5+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

char v[mod] {};

vector<int> iw, is, ia, id; //下标
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
		v[i] = c;
		if (c == 'D') {
			px[i] = px[i-1] + 1;
			id.push_back(i);
		}
		else if (c == 'A') {
			px[i] = px[i-1] - 1;
			ia.push_back(i);
		}
		else if (c == 'W') {
			py[i] = py[i-1] + 1;
			iw.push_back(i);
		}
		else if (c == 'S') {
			py[i] = py[i-1] - 1;
			is.push_back(i);
		}
	}
	
	int a, b;
	if (x > 0) {
		a = id[x-1];

		for (int i = 0; i < id.size(); i += x) {
			int l = id[i], r = id[i+x-1];
			if (y > 0) {
				
			}
		}
	} else if (x < 0) {
		a = ia[x-1];
	}

	if (y > 0) {
		b = iw[x-1];
	} else if (x < 0) {
		b = is[x-1];
	}


	return 0;
}