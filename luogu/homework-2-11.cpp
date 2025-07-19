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
    n->nxt = n;
    return n;
}

int length(N *n) {
    N* root = n;
    int r = 0;
    do {
        r++;
        n = n->nxt;
    } while (n != root);
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

    N* root = n;
    int r = 0;
    do {
        if (r == id) {
            break;
        }
        r++;
        n = n->nxt;
    } while (n != root);
    return n;
}

int loc(N *n, int v) {
    N* root = n;
    int r = 0;
    do {
        if (n->v == v) {
            return r;
        }
        r++;
        n = n->nxt;
    } while (n != root);
    return -1;
}

int display(N *n) {
    N* root = n;
    do {
        cout << n << " -> " << n->v << endl;
        n = n->nxt;
    } while (n != root);
    return 0;
}

void del(N* n, int i) {
    N* root = n;
    N* prev = get(n, i-1);
    N* current = n->nxt;
    int cnt = 1;

    do {
        if (cnt == i) {
            break;
        }
        prev = current;
        current = current->nxt;
        cnt++;
    } while (current != root);

    prev->nxt = current->nxt;
    delete current;
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

    cout << "--------------------" << endl;
    cout << "loc(root, 1) = " << loc(root, 1) << endl;
    cout << "loc(root, 5) = " << loc(root, 5) << endl;
    cout << "--------------------" << endl;

    cout << "del(root, loc(root, 5));" << endl;
    del(root, loc(root, 5));

    cout << "--------------------" << endl;

    display(root);

    return 0;
}
