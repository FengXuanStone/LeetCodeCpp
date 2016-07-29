//
// Created by fengxuan on 2016/7/29.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* pre = head;
        ListNode* p = head->next;

        while (p != NULL) {
            if(pre->val == p->val) {
                p = p->next;
            } else {
                pre->next = p;
                pre = p;
                p = p->next;
            }
        }

        pre->next = NULL;

        return head;
    }
};

int main() {
    cout << "Hello world" << endl;

    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(1);

    return 0;
}
