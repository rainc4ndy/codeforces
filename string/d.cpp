#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vb = vector<bool>;
#define rep(n) for (int _i_i_ = (n); _i_i_; --_i_i_)
#define mem(arr, x) memset((arr), x, sizeof (arr))
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define random rnd(chrono::system_clock::now().time_since_epoch().count())
#define setdb(v) setprecision(v)
#define all(x) x.begin(), x.end()
#define unq_all(x) x.erase(unique(all(x)), x.end())
#define sort_all(x) sort(all(x))
#define reverse_all(x) reverse(all(x))
#define x first
#define y second
#define YES cout << "YES\n"
#define Yes cout << "Yes\n"
#define NO cout << "NO\n"
#define No cout << "No\n"
#define pb push_back
#define eb emplace_back
#define nin ll n; cin >> n
//.........Bit_Manipulation...........//
#define msb(mask) (63-__builtin_clzll(mask))
#define lsb(mask) __builtin_ctzll(mask)
#define cntsetbit(mask) __builtin_popcount(mask)
#define checkbit(mask,bit) ((mask >> bit) & 1ll)
#define onbit(mask,bit) ((mask)|(1LL<<(bit)))
#define offbit(mask,bit) ((mask)&~(1LL<<(bit)))
#define changebit(mask,bit) ((mask)^(1LL<<bit))
#define setbit(mask,bit) ((mask)|(1LL<<(bit)))
#define resetbit(mask,bit) ((mask)&~(1LL<<(bit)))
#define togglebit(mask,bit) ((mask)^(1LL<<bit))
//.........Fast Input...........//
inline void read(int &a) { cin >> a; }
inline void read(ll &a) { cin >> a; }
inline void read(char &a) { cin >> a; }
inline void read(double &a) { cin >> a; }
inline void read(long double &a) { cin >> a; }
inline void read(string &a) { cin >> a; }
template<class T, class S>
void read(pair<T, S> &p) {
    read(p.first), read(p.second);
}
template<class T>
void read(vector<T> &a) {
    for (auto &i : a) read(i);
}
template<class T>
void read(T &a) {
    cin >> a;
}
#define TIME cout<<(double)clock()/CLOCKS_PER_SEC <<"ms"<<endl;
#define debug(x) cout << #x << ' ' << x << endl;
const int maxn = 2e5 + 10;
const ll mod = 998244353;


struct TrieNode {
    TrieNode* next[26] {};
    TrieNode* fail = nullptr;
    bool isEnd = false;
    int id = -1;
};

class ACAutomaton {
public:
    TrieNode* root = new TrieNode();
    vector<TrieNode*> nodes;

    void insert(const string& word, int id) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->next[idx])
                node->next[idx] = new TrieNode();
            node = node->next[idx];
        }
        node->isEnd = true;
        node->id = id;
        nodes.push_back(node);
    }

    void build() {
        queue<TrieNode*> q;
        root->fail = root;

        for (int i = 0; i < 26; ++i) {
            if (root->next[i]) {
                root->next[i]->fail = root;
                q.push(root->next[i]);
            } else {
                root->next[i] = root;
            }
        }

        while (!q.empty()) {
            TrieNode* curr = q.front(); q.pop();
            for (int i = 0; i < 26; ++i) {
                if (curr->next[i]) {
                    TrieNode* failTo = curr->fail;
                    while (!failTo->next[i]) {
                        failTo = failTo->fail;
                    }
                    curr->next[i]->fail = failTo->next[i];
                    q.push(curr->next[i]);
                }
            }
        }
    }

    int query(const string& text, int keywordCount) {
        TrieNode* node = root;
        vector<bool> found(keywordCount + 1, false);
        int count = 0;

        for (char ch : text) {
            int idx = ch - 'a';
            while (!node->next[idx]) node = node->fail;
            node = node->next[idx];

            TrieNode* temp = node;
            while (temp != root) {
                if (temp->isEnd && !found[temp->id]) {
                    found[temp->id] = true;
                    ++count;
                }
                temp = temp->fail;
            }
        }

        return count;
    }
};

void solve() {
    nin;
    ACAutomaton ac;

    for (int i = 1; i <= n; ++i) {
        string keyword;
        cin >> keyword;
        ac.insert(keyword, i);
    }

    string desc;
    cin >> desc;
    ac.build();
    cout << ac.query(desc, n) << '\n';
}

int main() {
    fastio;
    int _;
    cin >> _;
    while (_--) solve();

    return 0;
}