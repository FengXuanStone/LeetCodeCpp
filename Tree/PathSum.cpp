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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;

        return PathSum(root, sum, 0);
    }

    bool PathSum(TreeNode* root, int sum, int curr) {
        int tmp = curr + root->val;

        if(root->left == NULL && root->right == NULL) {
            if(tmp == sum) return true;
            else return false;
        }
        else {
            if(root->left != NULL && root->right != NULL) {
                return PathSum(root->left, sum, tmp)|| PathSum(root->right, sum, tmp);
            }
            else if(root->left != NULL) {
                return PathSum(root->left, sum, tmp);
            }
            else if(root->right != NULL) {
                return PathSum(root->right, sum, tmp);
            }
        }

        return true;
    }

    bool hasPathSum1(TreeNode* root, int sum) {
        if(root == NULL) return false;

        vector<int> count;
        vector<TreeNode*> candidate;
        candidate.push_back(root);
        count.push_back(0);

        while (!candidate.empty()) {
            vector<int> tmpCount;
            vector<TreeNode* > Tmpcandidate;
            for(int i = 0; i < candidate.size(); ++i) {
                auto currNode = candidate[i];
                if(currNode->left == NULL && currNode->right == NULL) {
                    if(count[i] + currNode->val == sum) return true;
                }
                if(currNode->left != NULL) {
                    tmpCount.push_back(count[i] + currNode->val);
                    Tmpcandidate.push_back(currNode->left);
                }
                if(currNode->right != NULL) {
                    tmpCount.push_back(count[i] + currNode->val);
                    Tmpcandidate.push_back(currNode->right);
                }
            }
            candidate = Tmpcandidate;
            count = tmpCount;
        }
        return false;
    }
};

int main() {
    cout << "Hello world" << endl;

    TreeNode* s1 = new TreeNode(1);
    //TreeNode* s2 = new TreeNode(2);
    //s1->left = s2;

    Solution* ss = new Solution;
    cout << ss->hasPathSum1(s1, 0) << endl;

    return 0;
}
