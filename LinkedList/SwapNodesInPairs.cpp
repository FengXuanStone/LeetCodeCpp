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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* first, * second, * tmp;
        first = head;
        second = head->next;
        head = second;
        tmp = first;

        while (first && second) {
            tmp->next = second;
            first->next = second->next;
            second->next = first;
            tmp = first;
            first = first->next;
            if(first != NULL) second = first->next;
        }

        return head;
    }
};

int main() {
    cout << "Hello world" << endl;

    ListNode* s1 = new ListNode(1);
    ListNode* s2 = new ListNode(2);
    s1->next = s2;

    Solution* ss = new Solution;
    ss->swapPairs(s1);

    return 0;
}
