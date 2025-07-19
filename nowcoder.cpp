#include <bits/stdc++.h> 

using namespace std;  
#define bsize (64)

int main() {
	int a, b;
	cin >> a >> b;

	string s1 = bitset<bsize>(a).to_string(), 
			s2 = bitset<bsize>(b).to_string();

	cout << stoll(s1) + stoll(s2);
	return 0;
}