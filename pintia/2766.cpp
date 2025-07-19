#include <bits/stdc++.h>
#include <cwchar>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        vector<int> ans;
        set<int> um;
        for (auto it :nums) {
            um.insert(it);
        }      
        for (int i = 0; i < moveFrom.size(); i++) {
            um.erase(moveFrom[i]);
            um.insert(moveTo[i]);
        }
        for (auto it : um)
            ans.push_back(it);
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //code

    return 0;
}