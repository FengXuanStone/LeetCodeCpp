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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;

        int len1 = 0;
        int len2 = 0;

        ListNode* x = headA;
        while (x != NULL) {
            x = x->next;
            ++len1;
        }
        x = headB;
        while (x != NULL) {
            x = x->next;
            ++len2;
        }

        if(len1 > len2) {
            int t = len1 - len2 - 1;
            while (t--) {
                headA = headA->next;
            }
            if(headA->next == headB) return headB;
            else headA = headA->next;
        } else if(len2 > len1){
            int t = len2 - len1 - 1;
            while (t--) {
                headB = headB->next;
            }
            if(headB->next == headA) return headA;
            else headB = headB->next;
        }

        while (headA != NULL) {
            if(headA == headB) return headA;
            else {
                headA = headA->next;
                headB = headB->next;
            }
        }

        return NULL;
    }
};

int main() {
    cout << "Hello world" << endl;

    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);

    Solution* ss = new Solution;
    ss->getIntersectionNode(l1,l2);

    return 0;
}
