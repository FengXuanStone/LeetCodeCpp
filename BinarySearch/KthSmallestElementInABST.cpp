//
// Created by fengxuan on 2016/8/7.
//
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL || k <= 0) return  0;

        stack<TreeNode* > candidate;
        TreeNode* tmp = root;

        while (tmp != NULL) {
            candidate.push(tmp);
            tmp = tmp->left;
        }

        while (k > 0 && (tmp != NULL || !candidate.empty())) {
            if(tmp == NULL) {
                tmp = candidate.top();
                candidate.pop();
                --k;
                if(k == 0) return tmp->val;
                else tmp = tmp->right;
            } else {
                candidate.push(tmp);
                tmp = tmp->left;
            }
        }

        return tmp->val;

    }
};

int main() {
    cout << "Hello world" << endl;

    TreeNode* t1 = new TreeNode(3);
//    TreeNode* t2 = new TreeNode(1);
//    TreeNode* t3 = new TreeNode(2);
//    TreeNode* t4 = new TreeNode(4);
//    t1->left = t2;
//    t2->right = t3;
//    t1->right = t4;

    Solution* ss = new Solution;
    ss->kthSmallest(t1, 1);


    return 0;
}
