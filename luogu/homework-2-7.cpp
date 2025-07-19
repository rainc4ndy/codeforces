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

int get(N *n, int id) {
	int r = 0;
	while (n != nullptr) {
		if (r == id) {
			return n->v;
		}
		r++;
		n = n->nxt;
	}
	return INT_MIN;
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

int main() {

    N *root = create(0);
   	insert(1, root);
   	insert(1, root);
   	insert(4, root);
   	insert(5, root);
   	insert(1, root);
   	insert(4, root);

	display(root);
   	cout << "length(root) = " << length(root) << endl;
   	cout << "loc(root, 4) = " << loc(root, 4) << endl;
   	cout << "get(root, loc(root, 4)) = " << get(root, loc(root, 4)) << endl;
	destroy(root);
	return 0;
}
