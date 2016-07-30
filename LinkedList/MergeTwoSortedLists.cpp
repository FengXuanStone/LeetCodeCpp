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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        ListNode* result;

        if(l1->val < l2->val) {
            result = l1;
            l1 = l1->next;
        } else {
            result = l2;
            l2 = l2->next;
        }

        ListNode* curr = result;

        while (l1 != NULL && l2 != NULL) {
            if(l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
                curr = curr->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
                curr = curr->next;
            }
        }

        if(l1 == NULL) curr->next = l2;
        else curr->next = l1;

        return result;
    }
};

int main() {
    cout << "Hello world" << endl;

    ListNode* s1 = new ListNode(1);
    ListNode* s2 = new ListNode(2);



    return 0;
}
