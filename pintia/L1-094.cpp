#include <bits/stdc++.h> 
 
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    string s, s1, s2, copy, tmp;
    cin >> s;

    int n, head, end;
    cin >> n;
 
 	int pos, cutted;
 	bool flag = false;
    for (int i = 0; i < n; i++) {
    	flag = false;
    	cin >> head >> end >> s1 >> s2;

    	//字符串位置从 1 开始编号
    	head--;
    	end--;

    	copy = s.substr(head, end - head + 1);
    	s.erase(head, end - head + 1);

    	//cout << "CUT: " << copy << endl;
    	//cout << "S: " << s << endl;

    	// 用于查找
    	tmp = s;

    	cutted = 0;
    	// 需要遍历查找，符合s1s2条件的位置可能在后面
    	while ((pos = tmp.find(s1)) != string::npos) {
    		//cout << pos << endl;
    		if (!tmp.substr(pos + s1.length(), s2.length()).compare(s2)) {
    			s.insert(cutted + pos + s1.length(), copy); //原字符串操作
    			flag = true;
    			break;
    		} else {
    			//不断缩短字符串
    			cutted += pos + s1.length();
    			tmp.erase(0, pos  + s1.length());
    		}
    	}
    	if (!flag)	
	    	s.append(copy);

    	//cout << "PASTE: " << s << endl;
    }

    cout << s;

	return 0;
}