#include <bits/stdc++.h> 
 
using namespace std;

int main() {

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int f, m, r;

	cin >> f >> m >> r;

	int mi = 10000000;
	int a1 = 0, a2 = 0;

	for (int i = 1; i < r; i++) {
		int p1 = f / i; //p1人间
		
		if (p1 != (float)f / (float)i || p1 == 1) {
			continue;
		}

		int p2 = m / (r - i);

		if (p2 != (float)m / (float)(r - i) || p2 == 1) {
			continue;
		}

		if (abs(p1 - p2) < mi) {
			mi = abs(p1 - p2);
			a1 = p1;
			a2 = p2;
		}
	}

	if (a1 == 0 || a2 == 0) {
		cout << "No Solution";
		return 0;
	}

	//所有的寝室都要分出去，最后不能有寝室留空
	if (f / a1 + m / a2 < 10) {
		cout << "No Solution";
		return 0;
	}

	cout << f / a1 << ' ' << m / a2;

	return 0;
}