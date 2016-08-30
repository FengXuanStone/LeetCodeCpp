//
// Created by fengxuan on 2016/8/30.
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;

        if(root == NULL) return result;

        vector<TreeNode* > candidate;
        candidate.push_back(root);

        while (!candidate.empty()) {
            result.push_back((*(candidate.end() - 1))->val);

            vector<TreeNode* > tmp;

            for(int i = 0; i < candidate.size(); ++i) {
                if(candidate[i]->left != NULL) tmp.push_back(candidate[i]->left);
                if(candidate[i]->right != NULL) tmp.push_back(candidate[i]->right);
            }

            candidate = tmp;
        }

        return result;
    }
};


int main() {
    cout << "Hello world" << endl;

    TreeNode* node = new TreeNode(1);

    Solution* ss = new Solution;
    ss->rightSideView(node);

    return 0;
}
