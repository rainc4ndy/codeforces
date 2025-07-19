#include <bits/stdc++.h>
#include <cwchar>
using namespace std;

class Solution {
public:
	Solution() {
	}
	int alternatingSubarray(vector<int>& nums) {

		int mx = 0;
		int cnt = 0;
		bool f = false, mode = false;
		for (int i = 0; i < nums.size(); i++) {
			if (i == nums.size() - 1) {
				if (!mode) {
					if (nums[i] - nums[i-1] == -1) {
						cnt++;
					}
				} else {
					if (nums[i] - nums[i-1] == 1) {
						cnt++;
					}
				}
				mode = 0;
				mx = max(mx, cnt);
				cnt = 0;
				continue;
			}
			if (!mode) {
				if (nums[i + 1] - nums[i] == 1) {
					cnt++;
					mode ^= 1;
				}
				else {
					mode = 0;
					mx = max(mx, cnt+1);
					cnt = 0;
					i--;
				}
			} else {
				if (nums[i + 1] - nums[i] == -1) {
					cnt++;
					mode ^= 1;
				}
				else {
					mode = 0;
					mx = max(mx, cnt+1);
					cnt = 0;
					i--;
				}
			}
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