//
// Created by fengxuan on 2016/7/30.
//
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL) return vector<vector<int>>();

        vector<vector<int>> result;
        vector<TreeNode* > candidate;
        candidate.push_back(root);

        while (!candidate.empty()) {
            vector<int> tmp;
            vector<TreeNode*> tmpNode;

            for(int i = 0; i < candidate.size(); ++i) {
                auto node = candidate[i];
                tmp.push_back(node->val);
                if(node->left != NULL) tmpNode.push_back(node->left);
                if(node->right != NULL) tmpNode.push_back(node->right);
            }
            result.push_back(tmp);
            candidate = tmpNode;
        }

        return vector<vector<int>>(result.rbegin(), result.rend());
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
