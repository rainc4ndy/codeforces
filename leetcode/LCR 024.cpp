#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *n = head;
        ListNode *pre = nullptr;
        ListNode *m;
        while (n != nullptr) {

            m = n->next;
            n->next = pre;

            pre = n;
            n = m;
        }
        return pre;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ListNode l[5];
    for (int i = 0; i < 5; i++) {
        l[i].val = i + 1;
        if (i != 4)
            l[i].next = &l[i + 1];
    }

    Solution s;
    ListNode *r = s.reverseList(l);

    ListNode *n = r;
    while (n != nullptr) {
        cout << n->val << ' ';
        n = n->next;
    }


    return 0;
}

