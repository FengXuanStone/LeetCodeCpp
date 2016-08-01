//
// Created by fengxuan on 2016/7/31.
//
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* s1 = new ListNode(0);
        s1->next = head;

        ListNode* pre = s1;
        ListNode* p = head;

        while (n--) p = p->next;

        while (p != NULL) {
            p = p->next;
            pre = pre->next;
        }

        pre->next = pre->next->next;
        head = s1->next;
        delete(s1);

        return head;
    }
};

int main() {
    cout << "Hello world" << endl;

    ListNode* l1 = new ListNode(1);
    Solution* ss = new Solution;
    ss->removeNthFromEnd(l1, 1);

    return 0;
}
