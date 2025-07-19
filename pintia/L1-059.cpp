#include <bits/stdc++.h> 
 
using namespace std;

std::vector<string> ans;

void solve() {

	vector<string> words;
	stringstream ss;

	string s;
	string tmp;
	std::getline(cin, s);

	int cen = s.find(",");

	bool o1 = false, o2 = false;

	//NOTICE: 上半句可能就一个字，拼音连3个都不到
	if (cen >= 3 && s.substr(cen - 3, 3) == "ong") {
		o1 = true;
	}	

	string part2 = s.substr(cen + 1, s.length() - cen + 1);
	int pos = 0;

	//通过find空格 不断缩短字符串的长度
	while ((pos = part2.find(' ')) != string::npos) {
		tmp = part2.substr(0, pos);

		//patched
		words.push_back(tmp);
		
		part2.erase(0, pos + 1); // +1 是空格字符的长度
	}
	if (part2.length() != 0) {
		words.push_back(part2); //剩下最后part2这是 最后一个词
	}

	if (part2.length() >= 4) {
		if (part2.substr(part2.length() - 4, 3) == "ong") {
			o2 = true;
		}
	}

	if (o1 && o2) {
		//输出前半句
		ss << s.substr(0, cen + 1);

		//分词输出后半句
		for (int i = 0; i < words.size() - 3; i++) {
			ss << words[i] << ' ';
		}
		ss << "qiao ben zhong.";
	} else {
		ss << "Skipped";	
	}

	ans.push_back(ss.str());
}

int main() {
    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int n = 0;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
    	solve();
    }

    for (int i = 0; i < n; i++) {
    	cout << ans[i];
    	if (i != n- 1)
    		cout << endl;
    }

	return 0;
}