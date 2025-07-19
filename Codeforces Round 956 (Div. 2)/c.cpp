#include <bits/stdc++.h> 
#include <cwchar>
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

int n;
int a[mod], b[mod], c[mod];

void solve() {
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sum /= 3;

	cout << "sum = " << sum << endl;

	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}

	int s1 = 0,s2 = 0,s3 = 0;	
	int ax = 0, ay=0;
	int bx = 0, by=0;
	int cx = 0, cy=0;

	int d1 = 0, 
		d2 = 0,
		d3 = 0;

	int tail = 1;
	for (int i = 1; i <= n; i++) {

		if (!ax && !ay)
			s1 += a[i];
		if (!bx && !by)
			s2 += b[i];
		if (!cx && !cy)
			s3 += c[i];

/*		if (s1 >= sum)
			d1 = abs(sum - s1);
		else d1 = 0x3f3f3f3f;
		
		if (s2 >= sum)
			d2 = abs(sum - s2);
		else d2 = 0x3f3f3f3f;
		
		if (s3 >= sum)
			d3 = abs(sum - s3);
		else d3 = 0x3f3f3f3f;*/

/*		cout << "d1 " << d1 << endl;
		cout << "d2 " << d2 << endl;
		cout << "d3 " << d3 << endl;
		cout << "s1 " << s1 << endl;*/

/*		if (s1 >= sum && d1 < d2 && d1 < d3) {
			ax = tail;
			ay = i;
			tail = i+1;

			s1 = 0;
			s2 = 0;
			s3 = 0;
		}
		else if (s2 >= sum && d2 < d1 && d2 < d3) {
			bx = tail;
			by = i;
			tail = i+1;

			s1 = 0;
			s2 = 0;
			s3 = 0;
		}
		else if (s3 >= sum && d3 < d2 && d3 < d1) {
			cx = tail;
			cy = i;
			tail = i+1;

			s1 = 0;
			s2 = 0;
			s3 = 0;
		}*/

		if (s1 >= sum && s1 > s2 && s1 > s3) {
			ax = tail;
			ay = i;
			tail = i+1;

			s1 = 0;
			s2 = 0;
			s3 = 0;
		}
		else if (s2 >= sum && s2 > s1 && s2 > s3) {
			bx = tail;
			by = i;
			tail = i+1;

			s1 = 0;
			s2 = 0;
			s3 = 0;
		}
		else if (s3 >= sum && s3 > s2 && s3 > s1) {
			cx = tail;
			cy = i;
			tail = i+1;

			s1 = 0;
			s2 = 0;
			s3 = 0;
		}
	}

/*	if (!ax || !ay ||
		!bx || !by ||
		!cx || !cy) {
		cout << -1 << endl;
	} else {*/
		cout << ax << ' ' << ay << ' ' 
			<< bx << ' ' << by << ' ' 
			<< cx << ' ' << cy << endl;
	//}
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int t;
    cin >> t;
    while(t--)
    	solve();

	return 0;
}