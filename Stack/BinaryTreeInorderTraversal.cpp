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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;

        if(root == NULL) return result;

        stack<TreeNode* > candidate;
        candidate.push(root);

        while (!candidate.empty()) {
            if(candidate.top()->left != NULL) {
                candidate.push(candidate.top()->left);
            }
             else {
                TreeNode* tmp = candidate.top();

                while (tmp->right == NULL) {
                    result.push_back(candidate.top()->val);
                    candidate.pop();
                    if(!candidate.empty()) tmp = candidate.top();
                    else return result;
                }
                result.push_back(candidate.top()->val);
                candidate.pop();

                candidate.push(tmp->right);
            }
        }

        return result;
    }
};

int main() {
    cout << "Hello world" << endl;

    TreeNode* s1 = new TreeNode(1);
    TreeNode* s2 = new TreeNode(2);
    TreeNode* s3 = new TreeNode(3);
    s1->right = s2;
    s2->left = s3;

    Solution* s = new Solution;
    s->inorderTraversal(s1);

    return 0;
}
