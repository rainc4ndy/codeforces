#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>

using namespace std;

class ACAutomaton {
public:
    struct Node {
        map<char, int> next;  // 子节点
        int fail;              // 失败指针
        vector<int> output;    // 终结节点，存储匹配到的模式串的索引
    };

    ACAutomaton() {
        nodes.push_back(Node()); // 根节点
    }

    void addPattern(const string& pattern, int idx) {
        int node = 0;
        for (char c : pattern) {
            if (!nodes[node].next.count(c)) {
                nodes[node].next[c] = nodes.size();
                nodes.push_back(Node());
            }
            node = nodes[node].next[c];
        }
        nodes[node].output.push_back(idx); // 终结节点
    }

    void build() {
        queue<int> q;
        // 根节点的失败指针指向根节点
        for (auto& pair : nodes[0].next) {
            int nextNode = pair.second;
            nodes[nextNode].fail = 0;
            q.push(nextNode);
        }

        while (!q.empty()) {
            int currentNode = q.front();
            q.pop();

            for (auto& pair : nodes[currentNode].next) {
                char c = pair.first;
                int nextNode = pair.second;
                int failNode = nodes[currentNode].fail;
                
                // 失败指针的转移
                while (failNode != 0 && !nodes[failNode].next.count(c)) {
                    failNode = nodes[failNode].fail;
                }

                if (nodes[failNode].next.count(c)) {
                    nodes[nextNode].fail = nodes[failNode].next[c];
                } else {
                    nodes[nextNode].fail = 0;
                }
                // 如果从失败指针可以匹配到模式串，也需要记录
                nodes[nextNode].output.insert(nodes[nextNode].output.end(),
                                             nodes[nodes[nextNode].fail].output.begin(),
                                             nodes[nodes[nextNode].fail].output.end());
                q.push(nextNode);
            }
        }
    }

    vector<int> search(const string& text) {
        vector<int> result;
        int node = 0;
        for (int i = 0; i < text.size(); ++i) {
            char c = text[i];
            while (node != 0 && !nodes[node].next.count(c)) {
                node = nodes[node].fail;
            }
            if (nodes[node].next.count(c)) {
                node = nodes[node].next[c];
            } else {
                node = 0;
            }

            for (int idx : nodes[node].output) {
                result.push_back(idx);
            }
        }
        return result;
    }

private:
    vector<Node> nodes;  // AC自动机的节点
};

int main() {
    ACAutomaton ac;
    ac.addPattern("he", 0);
    ac.addPattern("she", 1);
    ac.addPattern("his", 2);
    ac.addPattern("hers", 3);
    ac.build();

    string text = "ushers";
    vector<int> result = ac.search(text);

    for (int idx : result) {
        cout << "Pattern " << idx << " matched!" << endl;
    }

    return 0;
}
