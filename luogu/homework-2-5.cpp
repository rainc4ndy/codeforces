#include <bits/stdc++.h>
using namespace std;

const int SZ = 64;

vector<int> a(SZ), b(SZ), c;


void print() {
	cout<< "A: ";
	for(auto it : a)
		cout << it << ' ';
	cout << endl;
	cout << "B: ";
	for(auto it : b)
		cout << it << ' ';
	cout << endl;

}

template<typename T>
int find(vector<T> &v, T e) {
	int sz = v.size();
	for(unsigned i = 0; i < sz; ++i) {
		if (v[i] == e)
			return i;
	}
	return -1;
}

template<typename T>
void replace_optimal(vector<T> &v1, vector<T> &v2, vector<T> &v3) {
	map<T , int> m;
	for(auto it:v1)
		m[it]++;
	for(auto it:v2) {
		if (m[it] == 1)
			v3.push_back(it);
	}

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(unsigned i = 0; i < SZ; ++i) {
    	a[i] = (i % 2 == 0) ? i : i*i;
    	b[i] = (i % 5 == 0) ? i : i*i;
    }
    print();

	/*
	//O(n^2)
    int t;
    for(unsigned i = 0; i < SZ; ++i) {
    	if ((t = find<int>(b, a[i])) != -1) {
    		c.push_back(a[i]);
    	}
    }
    */

    //O(2n)
    replace_optimal<int>(a, b,c);

    cout << endl << endl;
    cout << "C: ";
    for (auto it : c) {

    	cout << it << ' ';
    }

	return 0;
}
