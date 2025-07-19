#include <bits/stdc++.h> 
#include <sstream>
 
using namespace std;

string f(string a) {
	stringstream ss;
	for (int i = 1; i < a.length(); i++) {
	  if (a[i] % 2 == a[i-1] % 2) {
	    ss << max(a[i], a[i-1]);
	  }
	}
	return ss.str();
}
int main() {
    

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    string s1,s2;
    cin >> s1 >> s2;

   	s1 = f(s1);
   	s2 = f(s2);

   	if (!s1.compare(s2)) {
   		cout << s1;
   	} else {
   		cout << s1 << endl << s2;
   	}

	return 0;
}