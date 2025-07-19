#include <bits/stdc++.h> 
#include <iomanip>
using namespace std;

bool sec[86401] {};

int main() {    
    /*ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
*/
	int n;
	cin >> n;

	int x, y, z;
	char c;

	int t1, t2;

	int u[86400] {};

	for (int i = 0; i < n; i++) {
		cin >> x >> c >> y >> c >> z;
		cin >> c;
		t1 = x*3600 + y*60 + z;


		cin >> x >> c >> y >> c >> z;
		t2 = x*3600 + y*60 + z;

		for (int j = t1 + 1; j < t2; j++) {
			sec[j] = true;
		}

		u[t1]++; u[t2]++;
		if (u[t1] > 1) {
			sec[t1] = 1;
		}
		if (u[t2] > 1) {
			sec[t2] = 1;
		}
	}

	int l;
	bool flag = false;
	for (int i = 0; i <= 86400; i++) {
		if (!sec[i]) {
			if (!flag) {
				l = i;
				flag = true;
			}
		} else {
			if (flag) {
				x = l % 3600;
				l /= 3600;
				y = l % 60;
				l /= 60;
				z = l;

				int r = i;

				cout << setw(2) << setfill('0') << x << ':'
					<<  setw(2) << setfill('0') << y << ':'
					<<  setw(2) << setfill('0') << z << " - ";

				x = r % 3600;
				r /= 3600;
				y = r % 60;
				r /= 60;
				z = r;

				cout << setw(2) << setfill('0') << x << ':'
					<<  setw(2) << setfill('0') << y << ':'
					<<  setw(2) << setfill('0') << z << endl;

				flag = false;
			}
		}
	}

	return 0;
}