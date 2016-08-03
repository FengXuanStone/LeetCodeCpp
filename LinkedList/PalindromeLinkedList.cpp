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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;

        ListNode* s1 = head, * s2 = head;

        while (s2 != NULL && s2->next != NULL) {
            s1 = s1->next;
            s2 = s2->next->next;
        }
        if(s2 != NULL) s1 = s1->next;

        s2 = reverseList(s1);

        while (s2 != NULL) {
            if(head->val != s2->val) return false;
            head = head->next;
            s2 = s2->next;
        }

        return  true;
    }

    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* pre = head;
        ListNode* p = head->next;

        while (p != NULL) {
            ListNode* tmp = p;
            p = p->next;
            tmp->next = pre;
            pre = tmp;
        }

        head->next = NULL;

        return pre;
    }
};

int main() {
    cout << "Hello world" << endl;
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    l1->next = l2;
    Solution * ss = new Solution;
    ss->isPalindrome(l1);

    return 0;
}
