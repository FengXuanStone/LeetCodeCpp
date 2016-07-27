//
// Created by fengxuan on 2016/7/27.
//
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;

        TreeNode* tmp = root->left;
        root->left = root-> right;
        root->right = tmp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }

    TreeNode* invertTree1(TreeNode* root) {
        if(root == NULL) return root;

        queue<TreeNode* > q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            TreeNode* tmp = node->left;
            node->left = node->right;
            node->right = tmp;
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
            q.pop();
        }

        return root;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
