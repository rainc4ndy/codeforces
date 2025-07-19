#include <iostream>
#include <algorithm>
using namespace std;

int maxProduct(int a, int b, int c, int operations) {
    int nums[] = {a, b, c};
    while (operations > 0) {
        sort(nums, nums + 3);
        nums[0]++;
        operations--;
    }
    return nums[0] * nums[1] * nums[2];
}

int main() {
    int t;
    cin >> t; 
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << maxProduct(a, b, c, 5) << endl;
    }
    return 0;
}
