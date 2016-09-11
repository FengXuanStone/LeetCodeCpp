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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool flag = false;
        vector<vector<int>> result;

        if(root == NULL) return result;

        vector<TreeNode* > candidate;
        candidate.push_back(root);

        while (!candidate.empty()) {
            vector<int> levelResult;
            vector<TreeNode* > tmp;

            for(auto i = candidate.cbegin(); i != candidate.cend(); ++i) {
                levelResult.push_back((*i)->val);
                if((*i)->left != NULL) tmp.push_back((*i)->left);
                if((*i)->right != NULL) tmp.push_back((*i)->right);
            }

            if(flag) reverse(levelResult.begin(), levelResult.end());
            result.push_back(levelResult);
            flag = !flag;

            candidate = tmp;
        }

        return result;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
