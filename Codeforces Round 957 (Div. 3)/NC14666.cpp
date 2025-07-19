#include <bits/stdc++.h> 
#include <deque>
using namespace std;

const int mod = 1e6+10;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> P;

ll v[mod];
ll cnt[mod];
int dd = 0;

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> v[i];
		cnt[i] = 0;
	}
	//一个明显的事实：对于v[i] 如果左边的v[i-1]要比大，那么v[i]只能看到左边的v[i-1]
	//如果新入队的元素比队尾小，那么哨兵对只有1，
	//如果新入队的元素比队尾大，那么哨兵可以与前面的队头看到，而且：队头往右可以看到的山，哨兵也可以看到

	deque<ll> dq;

	for (int i = 0; i < n; i++) {
		if (dq.size() >= 1) {
			if (v[i] > v[dq.back()]) {
				//破坏单调性
				cnt[dq.back()]++;
				cnt[i]++;

				if (v[i] >= v[dq.front()]) {
					cnt[i] += dq.size()-1;
					cnt[dq.front()]++;

					for (int j = 0; j < dq.front(); j++) {
						if (v[j] > v[dq.front()]) {
							cnt[j]++;
							cnt[i]++;
						}
					}
				} else {
					cnt[i] += dq.size()-1;
					cnt[dq.front()]++;
				}
				while(!dq.empty()) dq.pop_front();
			} else {

				cnt[dq.back()]++;
				cnt[i]++;
			}
		}
		dq.push_back(i);
	}

	for (int i = 0; i < n; i++) {
		cout << cnt[i] << ' ';
	}
	cout << endl;
	//cout << "Case #" << ++dd <<
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