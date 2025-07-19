#include <bits/stdc++.h>
#include <iterator>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
    	map<int, char> m = {
    		{1, 'I'},
    		{5, 'V'},
    		{10, 'X'},
    		{50, 'L'},
    		{100, 'C'},
    		{500, 'D'},
    		{1000, 'M'}
    	};
    	stringstream ss;

    	while (num != 0) {
    		for (auto it = m.rbegin(); it != m.rend(); it++) {
    			if (it->first <= num) {
    				if (num <= 1000) {
    					int tmp = num;
    					int cnt = 0;
    					while (tmp >= 10) {
					        tmp /= 10;
					        cnt++;
					    }

    					if (tmp == 4) {
    						ss << it->second << prev(it)->second;
    						num -= tmp * pow(10, cnt);
    						continue;
    					} else if (tmp == 9) {
    						ss << next(it)->second << prev(it)->second;
    						num -= tmp * pow(10, cnt);
    						continue;
    					}
    				}
    				int cnt = num / it->first;
    				num -= cnt * it->first;
    				for(int i = 0; i < cnt; i++) {
    					ss << it->second;
    				}
    			}
    		}
    	}
    	return ss.str();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num;

    cin >> num;

	Solution s;
	cout << s.intToRoman(num);

	return 0;
}
