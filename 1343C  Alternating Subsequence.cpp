#include <bits/stdc++.h> 
#include <algorithm>

#define mod (100001)
#define ll long long
  
int main() {
    using namespace std;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int n; 
	cin >> n; 

	ll data[mod] {};
	ll ans[mod] {};
	int len;
	for (int i = 0; i < n; i++) {
		cin >> len;
		for (int j = 0; j < len; j++) {
			cin >> data[j];
		}

		bool negative = data[0] < 0;
		int rear = 0, front = 0;
		ll m = 0;

		while (front < len) {
			cout << "  Rear: " << rear << "  Front: " << front << endl;

			if (negative == false) {
				if (data[front] < 0 || front >= len - 1) {
					m = data[rear];
					while (rear < front) {
						m = max(data[rear], m);
						rear++;
					}
					cout << "[-] Selected: " << m << endl;
					ans[i] += m;
					negative = true;
					if (front < len - 1) {
						continue;
					}
				}
			} else {
				if (data[front] > 0 || front >= len - 1) {
					m = data[rear];
					while (rear < front) {
						m = max(data[rear], m);
						rear++;
					}
					cout << "[+] Selected: " << m << endl;
					ans[i] += m;
					negative = false;
					if (front < len - 1) {
						continue;
					}
				}
			}
			front++;
		}
		
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i];
		if (i != n - 1)
			cout << endl;
	}

	return 0;
}