#include <bits/stdc++.h> 
#include <initializer_list>
#include <memory>
#include <vector>
using namespace std;

class Test {
public:
	Test(initializer_list<int> p) {
		for (auto &it:p) {
			v.push_back(it);
		}
	}
	vector<int> v;

	~Test() {
		cout << "Deconstructed" << endl;
	}
};

int main() {    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

	shared_ptr<Test> p(new Test(
		{1, 2, 3, 4, 5}
	));

	for (auto &it : p->v) {
		cout << it << ',';
	}
	
	return 0;
}