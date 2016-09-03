//
// Created by fengxuan on 2016/9/3.
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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;

        ListNode* first = head, *second = head;

        while (second->next && second->next->next) {
            first = first->next;
            second = second->next->next;

            if(first == second) {
                first = head;
                while (first != second) {
                    first = first->next;
                    second = second->next;
                }

                return first;
            }
        }

        return NULL;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
