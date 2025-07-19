#include <bits/stdc++.h> 
#include <iomanip>
#include <vector>
using namespace std;

#define mod (100001)
#define ll long long
#define x first
#define y second
typedef pair<int, int> P;

double a,b,c,d;

double f(double x) {
	return a*x*x*x + b*x*x + c*x + d;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	cin >> a >> b >> c >> d;
	for (int i = -100; i <= 99; i++) {
		if (!f(i)) {
			cout << setprecision(2) << fixed << (float)i << ' ';
			continue;
		}

		if (f(i) * f(i+1.0) < 0) {
			double l = i, r = i+1;
			double mid;

			while(r-l >= 0.001) {
				mid = (l+r)/2;
				if (f(mid) * f(r) <= 0) {
					l = mid;
				} else {
					r = mid;
				}
			}
			cout << setprecision(2) << fixed << r << ' ';
		}

	}

	return 0;
}