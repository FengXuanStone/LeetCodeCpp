//
// Created by fengxuan on 2016/8/7.
//
#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* oddHead = NULL, * oddEnd = NULL, * evenHead = NULL, * evenEnd = NULL;

        while (head != NULL) {
            if(oddHead == NULL) {
                oddHead = head;
                oddEnd = head;
            } else {
                oddEnd->next = head;
                oddEnd = oddEnd->next;
            }
            head = head->next;

            if(head != NULL) {
                if(evenHead == NULL) {
                    evenHead = head;
                    evenEnd = head;
                } else {
                    evenEnd->next = head;
                    evenEnd = evenEnd->next;
                }
                head = head->next;
            }
        }

        if(oddEnd != NULL) oddEnd->next = evenHead;
        else oddHead = evenHead;
        if(evenEnd != NULL) evenEnd->next = NULL;

        return oddHead;
    }
};

int main() {
    cout << "Hello world" << endl;
    ListNode* s1= new ListNode(2);
    ListNode* s2= new ListNode(1);
    ListNode* s3= new ListNode(4);
    ListNode* s4= new ListNode(3);
    ListNode* s5= new ListNode(6);
    ListNode* s6= new ListNode(5);
    ListNode* s7= new ListNode(7);
    ListNode* s8= new ListNode(8);
    s1->next = s2, s2->next = s3, s3->next = s4, s4->next = s5, s5->next = s6, s6->next = s7, s7->next = s8;

    Solution* ss = new Solution;
    ss->oddEvenList(s1);

    return 0;
}
