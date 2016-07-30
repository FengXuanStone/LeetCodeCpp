//
// Created by fengxuan on 2016/7/30.
//
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(balance(root) < 0) return false;
        else return true;
    }

    int balance(TreeNode* root) {
        if(root == NULL) return 0;

        int l = balance(root->left);
        int r = balance(root->right);

        if(l < 0 || r < 0) return -1;
        else{
            int tmp = abs(l - r);
            if(tmp <= 1) {
                return max(l, r) + 1;
            } else return -1;
        }
    }
};

int main() {
    cout << "Hello world" << endl;

    TreeNode* t1 = new TreeNode(1);
    TreeNode* t2 = new TreeNode(2);
    TreeNode* t3 = new TreeNode(2);
    t1->left = t2;
    t1->right = t3;
    TreeNode* t4 = new TreeNode(3);
    TreeNode* t5 = new TreeNode(3);
    t2->left = t4;
    t2->right = t5;
    TreeNode* t6 = new TreeNode(4);
    TreeNode* t7 = new TreeNode(4);
    t4->left = t6;
    t4->right = t7;

    Solution* ss = new Solution;
    cout << ss->isBalanced(t1) << endl;

    return 0;
}
