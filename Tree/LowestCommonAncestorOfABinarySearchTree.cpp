//
// Created by fengxuan on 2016/7/29.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* tmp = root;
        bool  flag = true;

        while (flag) {
            if(p->val < tmp->val && q->val < tmp->val) {
                tmp = tmp->left;
            } else if(p->val > tmp->val && q->val > tmp->val) {
                tmp = tmp->right;
            } else {
                flag = false;
            }
        }

        return tmp;
    }
};


int main() {
    cout << "Hello world" << endl;

    return 0;
}
