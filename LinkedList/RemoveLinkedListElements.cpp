//
// Created by fengxuan on 2016/8/1.
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return head;

        ListNode* s1 = new ListNode(0);
        s1->next = head;

        ListNode* p = head;
        ListNode* pre = s1;

        while (p != NULL) {
            if(p->val != val) {
                p = p->next;
                pre = pre->next;
            } else {
                ListNode* tmp = p;
                p = p->next;
                pre->next = pre->next->next;
                delete(tmp);
            }
        }

        head = s1->next;
        delete(s1);

        return head;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
