#include <bits/stdc++.h>
using namespace std;

typedef struct N{
	int v;
	N* nxt;
	N(): nxt(nullptr) {}
} N;

N* create(int v) {
	N* n = new N;
	n->v = v;
	return n;
}

int length(N *n) {
	int r = 0;
	while (n != nullptr) {
		r++;
		n = n->nxt;
	}
	return r;
}

void insert(int v, N *n) {
	N *e = new N;
	e->v = v;
	e->nxt = n->nxt;
	n->nxt = e;
}

N* get(N *n, int id) {
	if (id == 0)
		return n;
	if (id < 0)
		return nullptr;
	int r = 0;

	while (n != nullptr) {
		if (r == id) {
			break;
		}
		r++;
		n = n->nxt;
	}
	return n;
}

int loc(N *n, int v) {
	int r = 0;
	while (n != nullptr) {
		if (n->v == v) {
			return r;
		}
		r++;
		n = n->nxt;
	}
	return -1;
}

int display(N *n) {
	while (n != nullptr) {
		cout << n << " -> " << n->v << endl;
		n = n->nxt;
	}
	return 0;
}

void destroy(N *n) {
	while (n != nullptr) {
		N *nxt = n->nxt;
		delete n;
		n = nxt;
	}
}

void del(N* n, int i) {
    N* prev = get(n, i-1);
    N* current = n->nxt;
    int cnt = 0;

    while (current != nullptr) {
    	if (cnt == i) {
    		break;
    	}
    	prev = current;
    	current = current->nxt;
    	cnt++;
    }
    prev->nxt = current->nxt;
    delete current;
}

void del(N* n, N* e) {
	N* prev = n;
    N* current = n->nxt;

    while (current != nullptr) {
    	if (current == e) {
    		break;
    	}
    	prev = current;
    	current = current->nxt;
    }
    prev->nxt = current->nxt;
    delete current;
}

void delete_range(N *n, int low, int high) {
	N* back = get(n, low-1);
	N* tmp = nullptr;
    N* current = back->nxt;
    int cnt = high - low;

    while (current != nullptr && cnt != 0) {
    	cout << "*** Deleted " << current->v << endl;
    	tmp = current->nxt;
    	delete current;
    	current = tmp;
    	cnt--;
    }

    back->nxt = tmp;
}

int main() {

    N *root = create(0);
   	insert(1, root);
   	insert(1, root);
   	insert(4, root);
   	insert(5, root);
   	insert(1, root);
   	insert(4, root);

	display(root);

	//locN(root, 4);
	delete_range(root, 2, 5);
	//delete_range(root, 1, 3);

	cout << "--------------------" << endl;
   	//scout << "locN(4) = " << locN(root, 4)->v << endl;
	display(root);

	destroy(root);
	return 0;
}
