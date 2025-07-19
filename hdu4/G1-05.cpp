#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-6; // 浮点数误差

bool canGet24(vector<double> nums) {
    if (nums.size() == 1) {
        return fabs(nums[0] - 24.0) < EPS; // 终止条件
    }

    // 两层for，就是每次选两个数字
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {

            // 下一次需要计算的数字组合
            vector<double> nextNums;
            for (int k = 0; k < nums.size(); k++) {
                if (k != i && k != j) {
                    nextNums.push_back(nums[k]);
                }
            }

            // 两个数字之间所有可能的运算
            vector<double> results = {
                nums[i] + nums[j],
                nums[i] - nums[j],
                nums[j] - nums[i],
                nums[i] * nums[j],
                nums[i] / nums[j],
                nums[j] / nums[i]
            };

            for (double newNum : results) {
                nextNums.push_back(newNum);
                if (canGet24(nextNums)) return true;
                nextNums.pop_back();
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        vector<double> nums(4);
        for (int i = 0; i < 4; i++) {
            cin >> nums[i];
        }
        cout << (canGet24(nums) ? "True" : "False");
        if (T != 0) cout << " ";
    }
    return 0;
}
