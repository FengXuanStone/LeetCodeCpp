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


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        ListNode* p = head;
        while (p != NULL) {
            p = p->next;
            ++n;
        }
        if(n == 0) return NULL;

        return sortedListToBST(head, 0, n - 1);
    }

    TreeNode* sortedListToBST(ListNode *&head, int start, int end) {
        if (start > end) return NULL;

        int mid = start + (end - start) / 2;
        TreeNode* left = sortedListToBST(head, start, mid - 1);
        int x = head->val;

        TreeNode* root = new TreeNode(x);
        root->left = left;
        head = head->next;
        root->right = sortedListToBST(head, mid + 1, end);

        return root;
    }
};

int main() {
    cout << "Hello world" << endl;

    ListNode* l1 = new ListNode(3);
    ListNode* l2 = new ListNode(5);
    ListNode* l3 = new ListNode(8);
    l1->next = l2;
    l2->next = l3;

    Solution* ss = new Solution;
    TreeNode* root = ss->sortedListToBST(l1);

    cout << root->val << endl;
    return 0;
}
