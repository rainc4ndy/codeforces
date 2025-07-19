#include <bits/stdc++.h>
#include <memory>
#include <vector>

using namespace std;

const int mod = 2e5 + 10;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<int, int> P;

template <typename K, typename V>
struct SkipListNode {
	int level;
	K key;
	V value;
	SkipListNode **forward;

	SkipListNode() {}

	SkipListNode(K k, V v, int l, SkipListNode *nxt = NULL) {
		key = k;
		value = v;
		level = l;
		forward = new SkipListNode *[l + 1];
		for (int i = 0; i <= l; ++i) forward[i] = nxt;
	}

	~SkipListNode() {
		if (forward != NULL) delete[] forward;
	}
};

template <typename K, typename V>
struct SkipList {
	static constexpr int MAXL = 32;
	static constexpr int P = 4;
	static constexpr int S = 0xFFFF;
	static constexpr int PS = S / P;
	static constexpr int INVALID = INT_MAX;

	SkipListNode<K, V> *head, *tail;
	int length;
	int level;

	SkipList() {
		srand(time(nullptr));

		level = length = 0;
		tail = new SkipListNode<K, V>(INVALID, 0, 0);
		head = new SkipListNode<K, V>(INVALID, 0, MAXL, tail);
	}

	~SkipList() {
		delete head;
		delete tail;
	}

	int randomLevel() {
		int lv = 1;
		while ((rand() & S) < PS) ++lv;
		return MAXL > lv ? lv : MAXL;
	}

	void insert(const K &key, const V &value) {
		SkipListNode<K, V> *update[MAXL + 1];

		SkipListNode<K, V> *p = head;
		for (int i = level; i >= 0; --i) {
			while (p->forward[i]->key < key) {
				p = p->forward[i];
			}
			update[i] = p;
		}
		p = p->forward[0];

		if (p->key == key) {
			p->value = value;
			return;
		}

		int lv = randomLevel();
		if (lv > level) {
			lv = ++level;
			update[lv] = head;
		}

		SkipListNode<K, V> *newNode = new SkipListNode<K, V>(key, value, lv);
		for (int i = lv; i >= 0; --i) {
			p = update[i];
			newNode->forward[i] = p->forward[i];
			p->forward[i] = newNode;
		}

		++length;
	}

	bool erase(const K &key) {
		SkipListNode<K, V> *update[MAXL + 1];
		SkipListNode<K, V> *p = head;

		for (int i = level; i >= 0; --i) {
			while (p->forward[i]->key < key) {
				p = p->forward[i];
			}
			update[i] = p;
		}
		p = p->forward[0];

		if (p->key != key) return false;

		for (int i = 0; i <= level; ++i) {
			if (update[i]->forward[i] != p) {
				break;
			}
			update[i]->forward[i] = p->forward[i];
		}

		delete p;

		while (level > 0 && head->forward[level] == tail) --level;
		--length;
		return true;
	}

	V &operator[](const K &key) {
		V v = find(key);
		if (v == tail->value) insert(key, 0);
		return find(key);
	}

	V &find(const K &key) {
		SkipListNode<K, V> *p = head;
		for (int i = level; i >= 0; --i) {
			while (p->forward[i]->key < key) {
				p = p->forward[i];
			}
		}
		p = p->forward[0];
		if (p->key == key) return p->value;
		return tail->value;
	}


	/*
		int cnt = 0;
	for (int i = 0; i < 1e5; ++i) {
		int k = rand();
		if (m.erase(k)) {
			cnt++;
		}
	}

	cout << "Removed " << cnt << " nodes" << endl;
	*/

	bool count(const K &key) { return find(key) != tail->value; }
};

void solve() {
	SkipList<int, int> m;

	clock_t s = clock();

	const constexpr int scale = 1e5;
	cout << "Testing scale: " << scale << endl;
	for (int i = 0; i < scale; ++i) {
		int k = rand(), v = rand();
		m.insert(k, v);
	}
	cout << "Insertion completed." << endl;

	int cnt = 0;
	for (int i = 0; i < 1e5; ++i) {
		int k = rand();
		if (m.find(k) != m.tail->value) {
			cnt++;
		}
	}

	cout << cnt << " nodes were found" << endl;

	clock_t e = clock();
	cout << "Time elapsed: " << (double)(e - s) / CLOCKS_PER_SEC << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int _ = 1;
	while (_--)
		solve();

	return 0;
}