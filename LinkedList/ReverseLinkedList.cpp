//
// Created by fengxuan on 2016/7/28.
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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;

        ListNode* pre = NULL;
        ListNode* p = head;

        while (p->next != NULL) {
            ListNode* next = p->next;
            p->next = pre;
            pre = p;
            p = next;
        }

        p->next = pre;

        return  p;
    }

    ListNode* reverseList1(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* pre = head;
        ListNode* p = head->next;
        pre->next = NULL;
        ListNode* nxt;
        while(p!= NULL) {
            nxt = p->next;
            p->next = pre;
            pre = p;
            p = nxt;
        }
        return pre;

    }
};

int main() {
    cout << "Hello world" << endl;

    ListNode *s1 = new ListNode(1);
    ListNode *s2 = new ListNode(2);
    s1->next = s2;

    Solution *ss = new Solution;
    ss->reverseList(s1);

    return 0;
}
