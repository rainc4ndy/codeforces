#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    std::getline(cin, s);

    int l = s.length();
    int low, high;
    bool flag;

    //从最长的长度开始枚举，然后从第一次字符往后移动
    for(unsigned i = l; i >= 2; --i) {
    	low = 0;
    	high = i;
    	while (high <= l) {
    		flag = true;
    		for(unsigned j = 0; j < (high-low) / 2; ++j) {
    			if (s[low+j] != s[high-j-1]) {
    				flag = false;
    				break;
    			}
    		}
    		if (flag) {
    			cout << high-low << endl;
    			return 0;
    		}

    		low++;
    		high++;
    	}
    }

    cout << 1 << endl;

	return 0;
}
