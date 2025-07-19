#include <bits/stdc++.h> 
#include <iomanip>
#include <vector>
using namespace std;

#define mod (105)
#define ll long long
#define x first
#define y second
typedef pair<float, float> P;

P v[mod] {};

bool cmp(P& a, P& b) {
	if (a.x == 0 && b.x == 0)
		return false;
	return a.y / a.x > b.y / b.x;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int n, t;
    cin >> n >> t;

    for (int i = 0 ; i <n; i++) {
    	cin >> v[i].x >> v[i].y; 
    }

    float ans = 0;

    sort(v, v+n, cmp);
    int p = 0;
    while (t > 0) {	
    	if (t - v[p].x < 0) {
    		ans += (v[p].y / v[p].x) * t;
    		cout << "(v[p].y / v[p].x) * t = " << (v[p].y / v[p].x) * t << endl;
    		break;
    	} else { 
    		ans += v[p].y;
    		t -= v[p].x;
    		cout << "v[p].y = " << v[p].y << endl;
    		p++;
    	}
    	if (p >= n)
    		break;
    }

    cout << setprecision(2) << fixed << ans;

	return 0;
}