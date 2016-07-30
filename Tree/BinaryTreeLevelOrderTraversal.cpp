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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if(root == NULL) return result;

        vector<TreeNode* > candidate;
        candidate.push_back(root);

        while (!candidate.empty()) {
            vector<int> tmp;
            vector<TreeNode* > next;
            for(int i = 0; i < candidate.size(); ++i) {
                if(candidate[i] != NULL) {
                    tmp.push_back(candidate[i]->val);
                    next.push_back(candidate[i]->left);
                    next.push_back(candidate[i]->right);
                }
            }
            if(!tmp.empty()) result.push_back(tmp);
            candidate = next;
        }

        return result;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
