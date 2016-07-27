//
// Created by fengxuan on 2016/7/27.
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
    void deleteNode(ListNode* node) {
        if(node == NULL) return;

        ListNode* tmp = node->next;

        node->val = node->next->val;
        node->next = node->next->next;

        delete(tmp);
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
