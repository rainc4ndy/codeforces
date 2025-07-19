#include <bits/stdc++.h> 
#include <thread>
#include <vector>
using namespace std;

int e = 0;

bool finished = false;

void f() {
	e++;
	cout << "test " << e << endl;
}


int main() {    

	vector<thread> v;
    for (int i = 0; i < 20; i++) {
    	v.emplace_back(f);
    }

    for (auto& it:v)
    	it.join();

	return 0;
}