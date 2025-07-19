#include <bits/stdc++.h> 
#include <cwchar>
using namespace std;

class Solution {
	int v[10001];
public:
	Solution() {
   		memset(v, 0, sizeof(v));
	}
    int alternatingSubarray(vector<int>& nums) {
    	int mx = -1, cnt = 1, p = 0;
    	int pre = 0x3f3f3f3f;
   		for (auto it : nums) {
   			if (abs(it - pre) == 1) {
   				if (!v[it]) {
   					v[it]++;
   					p++;
   				}
   				if (p > 2) {
   					cnt = 1;
   					p = 0;
   					memset(v, 0, sizeof(v));
   					continue;
   				}
   				cnt++;
   				mx = max(mx, cnt);
   			} else {
   				cnt =1;
   				p = 0;
   				memset(v, 0, sizeof(v));
   			}
   			pre = it;
   		}
   		return mx;
    }
};

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	//code

	return 0;
}