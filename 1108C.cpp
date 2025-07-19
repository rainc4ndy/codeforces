#include <bits/stdc++.h> 
#include <vector>

using namespace std;

const int mod = 2e5+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;
	
char v[mod] {};

struct st {
	int r,g,b;
	vector<char> seq;
	st() : r(0), g (0), b(0) {}
};

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	st d[3];	
	for (int i = 0; i < n; i+=3) {
		for (int j = 0; j < 3; j++) {
			if (v[i+j] == 'R') {
				d[j].r++;
			}
			
			if (i+j >= n)
				continue;
			
			else if (v[i+j] == 'G') {
				d[j].g++;
			}

			if (i+j >= n)
				continue;
			
			else if (v[i+j] == 'B') {
				d[j].b++;
			}
		}
	}

	int ans = 0;

	st *mr=0,*mg=0,*mb=0;
	int x=0,y=0,z=0;
	for (int i = 0; i < 3; i++) {
		if (d[i].r > x) {
			x = d[i].r;
			mr = &d[i];
		}
		else if (d[i].g > y) {
			y = d[i].g;
			mg = &d[i];
		}
		else if (d[i].b > z) {
			y = d[i].b;
			mb = &d[i];
		}
	}

	ans = mr->g + mr->b +
			mg->r + mg->b +
			mb->g + mb->r;

	cout << ans;

	return 0;
}