//
// Created by fengxuan on 2016/8/27.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>
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
    TreeNode * pre = nullptr;

    bool isValidBST(TreeNode* root) {
        if(root != NULL) {
            if(!isValidBST(root->left)) return false;

            if(pre != NULL && root->val <= pre->val) return false;

            pre = root;

            return isValidBST(root->right);
        }
        return true;
    }
};

int main() {
    cout << "Hello world" << endl;

    strcmp("a","v");

    return 0;
}
