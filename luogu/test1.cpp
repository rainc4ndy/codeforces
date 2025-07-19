#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
using namespace std;

int v[] = {1, 2, 3, 4, 5};

void print_data() {
	for(unsigned i = 0; i < 5; ++i) {
		cout << v[i];
	}
	cout << endl;
}

void my_perm(int begin, int end) {
    if (begin == end - 1) {
        print_data(); // 当只剩下一个元素时，打印当前排列
        return;
    }
    for (int i = begin; i < end; ++i) {
        std::swap(v[begin], v[i]); // 交换当前元素与后续元素
        my_perm(begin + 1, end); // 递归地排列剩下的元素
        std::swap(v[begin], v[i]); // 恢复原状以进行下一次循环
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    my_perm(0, 5);
    /*int v[10] {};
  
	for (int i = 1; i <= 5; i++) {
		v[i - 1] = i;
	}

	do {
		for(unsigned i = 0; i < 5; ++i) {
			cout << v[i];
		}
		cout  << endl;
	} while (next_permutation(v,v + 5));*/

	return 0;
}
