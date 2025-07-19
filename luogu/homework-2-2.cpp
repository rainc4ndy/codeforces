#include <bits/stdc++.h>
using namespace std;
//sequential list

template<class T>
class MyList {
private:
	static const int SZ = 64;
	T data[SZ];
	int size;
public:
	MyList() {
		size = 0;
		memset(data, 0, sizeof(data));
	}
	// 时间复杂度 O(1)
	int length() { return size;}

	// 时间复杂度 O(1)
	int get(int b) { return (b < 0 || b > size) ? 0 : data[b]; }
	bool insert(T a, int b) {
		// 时间复杂度 O(n)
		if (b < 0 || b > size)
			return false;
		if (size == SZ)
			return false;
		for(unsigned i = size; i > b; --i)
			data[i] = data[i - 1];
		data[b] = a;
		size++;
		return true;
	}
	bool del(int b) {
		// 时间复杂度 O(n)
		if (b < 0 || b > size)
			return false;
		for(unsigned i = b; i < size; ++i)
			data[i] = data[i + 1];
		size--;
		return true;
	}
	int find(T a) {
		// 时间复杂度 O(n)
		for(unsigned i = 0; i < size; ++i) {
			if (data[i] == a)
				return i;
		}
		return -1;
	}

	void print() {
		// 时间复杂度 O(n)
		for(unsigned i = 0; i < size; ++i) {
			cout << data[i] << ' ';
		}
		cout << endl;
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    MyList<int> l;
    cout << "Empty list created." << endl;

   	int rear = 0, front = 8;
   	for(unsigned i = rear; i < front; ++i) {
   		cout << "Insert  " << i << " into list at index 0 " << endl;
   		l.insert(i, 0);
   		l.print();
   		cout << endl;
   	}

   	for(unsigned i = rear; i < front; i += 2) {
   		cout << "Insert 13 " << " into list at index "<< i << endl;
   		l.insert(13, i);
   		l.print();
   		cout << endl;
   	}

  	cout << "Length of the list: " << l.length() << endl;
  	cout << "Location : Value" << endl;
  	for(unsigned i = rear; i < front; ++i) {
  		cout << setfill('0') << setw(5) << l.find(i) << " : ";
  		cout << setfill('0') << setw(5) << i << endl;
  	}

	return 0;
}
