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
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;

        ListNode* first = head;
        ListNode* second = head->next;

        while (second != NULL && second->next != NULL) {
            if(first == second) return true;
            else {
                first = first->next;
                second = second->next->next;
            }
        }

        return false;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
