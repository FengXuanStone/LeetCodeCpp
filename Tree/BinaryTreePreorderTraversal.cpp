//
// Created by fengxuan on 2016/8/6.
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;

        if(root == NULL) return result;

        stack<TreeNode*> candidate;
        candidate.push(root);

        while (!candidate.empty()) {
            auto node = candidate.top();
            candidate.pop();

            result.push_back(node->val);

            if(node->right != NULL) candidate.push(node->right);
            if(node->left != NULL) candidate.push(node->left);
        }

        return result;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
