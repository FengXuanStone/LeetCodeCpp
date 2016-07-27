//
// Created by fengxuan on 2016/7/27.
//
#include <iostream>
#include <vector>

using namespace std;


//Definition for a binary Tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        vector<TreeNode* > candidate;
        int depth = 0;
        candidate.push_back(root);

        while(!candidate.empty()) {
            vector<TreeNode* > tmp;
            for(auto i = candidate.begin(); i != candidate.end(); ++i) {
                if((*i)->left != NULL) tmp.push_back((*i)->left);
                if((*i)->right != NULL) tmp.push_back((*i)->right);
            }
            depth++;
            candidate = tmp;
        }

        return depth;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
