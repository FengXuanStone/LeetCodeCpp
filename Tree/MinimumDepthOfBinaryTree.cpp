//
// Created by fengxuan on 2016/7/31.
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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int result = 1;
        vector<TreeNode* > candidate;
        candidate.push_back(root);

        while(!candidate.empty()) {
            vector<TreeNode* > tmp;
            for(int i = 0; i < candidate.size(); ++i) {
                if(candidate[i]->left == NULL && candidate[i]->right == NULL) return result;
                else {
                    if(candidate[i]->left != NULL) tmp.push_back(candidate[i]->left);
                    if(candidate[i]->right != NULL) tmp.push_back(candidate[i]->right);
                }
            }
            candidate = tmp;
            ++result;
        }

        return result;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
