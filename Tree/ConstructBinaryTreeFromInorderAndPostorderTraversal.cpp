//
// Created by fengxuan on 2016/9/9.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty() || postorder.empty()) return NULL;

        return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder,
                        int inorderLeft, int inorderRight, int postorderLeft, int postorderRight) {
        TreeNode* cur;

        if(inorderLeft > inorderRight || postorderLeft > postorderRight) return NULL;

        if(inorderLeft == inorderRight && postorderLeft == postorderRight) {
            cur = new TreeNode(inorder[inorderLeft]);
        } else {
            int tmp = postorder[postorderRight];
            cur = new TreeNode(tmp);

            int i = inorderLeft;
            for(; i <= inorderRight; ++i)
                if(inorder[i] == tmp) break;

            int postMid = postorderLeft + (i - inorderLeft);
            cur->left = buildTree(inorder, postorder, inorderLeft, i - 1, postorderLeft, postMid - 1);
            cur->right = buildTree(inorder, postorder, i + 1, inorderRight, postMid, postorderRight - 1);
        }

        return cur;
    }
};

int main() {
    cout << "Hello world" << endl;
    vector<int> vec1{2,1};
    vector<int> vec2{2,1};
    Solution* ss = new Solution;

    TreeNode* root = ss->buildTree(vec1, vec2);

    cout << root->val << endl;

    return 0;
}
