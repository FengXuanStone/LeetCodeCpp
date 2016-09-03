//
// Created by fengxuan on 2016/9/3.
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
    void flatten(TreeNode* root) {
        if(root == NULL) return;

        TreeNode* cur = root;
        vector<TreeNode* > candidate;
        stack<TreeNode* > tmp;
        tmp.push(root);
        candidate.push_back(tmp.top());

        while (!tmp.empty()) {
            while (tmp.top()->left != NULL) {
                tmp.push(tmp.top()->left);
                candidate.push_back(tmp.top());
            }

            while (!tmp.empty() && tmp.top()->right == NULL) tmp.pop();
            if(!tmp.empty()) {
                TreeNode* ss = tmp.top();
                tmp.pop();
                tmp.push(ss->right);
                candidate.push_back(tmp.top());
            }
        }

        int i = 0;
        for(; i < candidate.size() - 1; ++i) {
            candidate[i]->left = NULL;
            candidate[i]->right = candidate[i + 1];
        }
        candidate[i]->left = NULL;
        candidate[i]->right = NULL;
    }

    void flatten1(TreeNode* root) {
        while (root) {
            if (root->left && root->right) {
                TreeNode* t = root->left;
                while (t->right)
                    t = t->right;
                t->right = root->right;
            }

            if(root->left)
                root->right = root->left;
            root->left = NULL;
            root = root->right;
        }
    }
};

int main() {
    cout << "Hello world" << endl;

    TreeNode* root = new TreeNode(1);
    TreeNode* root1 = new TreeNode(2);
    root->left = root1;
    Solution* ss = new Solution;
    ss->flatten(root);

    while(root != NULL) {
        cout << root->val << ' ';
        root = root->right;
    }
    cout << endl;

    return 0;
}
