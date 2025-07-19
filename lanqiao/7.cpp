#include <bits/stdc++.h> 
using namespace std;

#define mod (100001)
#define ll long long

int v[mod] {};
int n, m;
int mx = 0;

bool check(int x) {
	int head = m + (m-1)*x -1, rear = 0;
	int mi = 0x3f3f3f3f;

	vector<int> dis;
	
	while (head < n) {
		dis.clear();
		for (int i = rear; i <= head; i += x+1) {
			if (i != head)
				dis.push_back(v[i+(x+1)] - v[i]);
		}

		for (auto it : dis) {
			mi = min(it, mi);
		}
		
		head++;
		rear++;
	}

	if (mi > mx) {
		mx = mi;
		return true;
	}

	return false;
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
	
	cin >> n >> m;


	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v, v+n);

	int low = 0, high = n / m; //间隔多少个位置]
	int mid;
	while (low <= high) {
		mid = (low+high) >> 1;
		if (check(mid)) 
			low = mid+1;
		else
			high = mid-1;

	}

	cout << mx;


	return 0;
}