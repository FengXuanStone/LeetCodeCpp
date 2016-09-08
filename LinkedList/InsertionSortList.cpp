//
// Created by fengxuan on 2016/9/8.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* cur = head->next;
        ListNode* result = head;
        result->next = NULL;

        while (cur) {
            ListNode* tmp = result;
            ListNode* pre = NULL;

            while (tmp != NULL && cur->val > tmp->val) {
                pre = tmp;
                tmp = tmp->next;
            }

            ListNode* ss = cur;
            cur = cur->next;

            if(pre == NULL) {
                ss->next = result;
                result = ss;
            } else {
                ss->next = tmp;
                pre->next = ss;
            }
        }

        return result;
    }

    ListNode* insertionSortList1(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* new_head = new ListNode(0);
        new_head -> next = head;
        ListNode* pre = new_head;
        ListNode* cur = head;
        while (cur) {
            if (cur -> next && cur -> next -> val < cur -> val) {
                while (pre -> next && pre -> next -> val < cur -> next -> val)
                    pre = pre -> next;
                /* Insert cur -> next after pre.*/
                ListNode* temp = pre -> next;
                pre -> next = cur -> next;
                cur -> next = cur -> next -> next;
                pre -> next -> next = temp;
                /* Move pre back to new_head. */
                pre = new_head;
            }
            else cur = cur -> next;
        }
        ListNode* res = new_head -> next;
        delete new_head;
        return res;
    }
};

int main() {
    cout << "Hello world" << endl;

    ListNode* l1 = new ListNode(3);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(4);
    l1->next = l2;
    l2->next = l3;
    Solution * ss = new Solution;
    ListNode* result = ss->insertionSortList(l1);

    while(result != NULL) {
        cout << result->val;
        result = result->next;
    }

    cout << endl;

    return 0;
}
