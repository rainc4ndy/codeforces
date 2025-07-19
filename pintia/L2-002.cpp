#include <bits/stdc++.h> 
#include <unordered_map>
 
using namespace std;

struct node {
	int k;
	int nxt;
};

node mem[100001]; //内存空间

int main() {
    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

   	unordered_map<int, bool> key_rec;

	int beg, n;
	int addr;

	cin >> beg >> n;

	// get
	for (int i = 0; i < n; i++) {
		cin >> addr >> mem[addr].k >> mem[addr].nxt;
	}

	// set
	int ptr = beg, next, ptr_prev = -1;
	int dptr_beg = -1, dptr_prev = -1; //dptr_beg "删除列表"的第一个节点的地址

	while (ptr != -1) {
		if (ptr_prev != ptr) {
			//判断ptr的位置是否前进
			if (key_rec.count(abs(mem[ptr].k)) == 0) {
	   			// 键值第一次出现
	   			key_rec[abs(mem[ptr].k)] = true;

   				ptr_prev = ptr;
	   		} 
		}
   		
   		//check for next one
   		//不断缩小重复链表的长度，直到下一个节点的key的绝对值是unique的
   		next = mem[ptr].nxt;
   		if (key_rec.count(abs(mem[next].k)) != 0 && next != -1) {
   			// already exist K
   			mem[ptr].nxt = mem[next].nxt; //skip & link

   			// add to deleted
   			if (dptr_beg == -1) {
   				dptr_beg = next; //next 作为删除列表第一个节点
   			} else {
   				mem[dptr_prev].nxt = next;
   			}
   			mem[next].nxt = -1;
   			dptr_prev = next;
   		} else {
   			ptr = next;
	   		// move on，前进
   		}
	}

	ptr = beg;
	while (ptr != -1) {
		if (mem[ptr].nxt == -1) 
			printf("%05d %d %d\n", ptr, mem[ptr].k, mem[ptr].nxt);
		else 
			printf("%05d %d %05d\n", ptr, mem[ptr].k, mem[ptr].nxt);
		ptr = mem[ptr].nxt;
	}


	ptr = dptr_beg;
	while (ptr != -1) {
		if (mem[ptr].nxt == -1) 
			printf("%05d %d %d\n", ptr, mem[ptr].k, mem[ptr].nxt);
		else 
			printf("%05d %d %05d\n", ptr, mem[ptr].k, mem[ptr].nxt);
		ptr = mem[ptr].nxt;
	}

	return 0;
}