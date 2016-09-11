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
    ListNode* partition(ListNode* head, int x) {
        ListNode* tmp = new ListNode(0);
        tmp->next = head;

        ListNode* i = tmp;
        ListNode* j = tmp;

        while(i->next != NULL) {
            if(i->next->val < x) {
                if(i == j) {
                    i = i->next;
                    j = j->next;
                } else {
                    ListNode* ss = i->next;
                    i->next = i->next->next;
                    ss->next = j->next;
                    j->next = ss;
                    j = j->next;
                }
            } else {
                i = i->next;
            }
        }

        return tmp->next;
    }
};

int main() {
    cout << "Hello world" << endl;
    ListNode* l1 = new ListNode(1);
    //ListNode* l2 = new ListNode(1);
//    ListNode* l3 = new ListNode(3);
//    ListNode* l4 = new ListNode(2);
//    ListNode* l5 = new ListNode(5);
//    ListNode* l6 = new ListNode(2);
    //l1->next = l2;
   // l2->next = l3;
    //l3->next = l4;l4->next = l5;l5->next = l6;

    Solution* ss = new Solution;
    ListNode* result = ss->partition(l1, 2);

    while (result != NULL) {
        cout << result->val << ' ';
        result = result->next;
    }

    cout << endl;

    return 0;
}
