#include <bits/stdc++.h> 
#include <thread>
#include <vector>
using namespace std;

void f(string &s) {
	cout << "s = " << s << endl;
}

int main() {    

	std::thread t(f, string("test"));
	t.join();
	return 0;
}