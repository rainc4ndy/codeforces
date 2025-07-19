#include <bits/stdc++.h> 
#include <initializer_list>
using namespace std;

void test(initializer_list<string> t) {
	for (auto& it:t) {
		cout << it << ',';
	}
}

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    test({"apple", "sword"});

	return 0;
}
