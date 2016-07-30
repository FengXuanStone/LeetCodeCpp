//
// Created by fengxuan on 2016/7/30.
//
#include <iostream>
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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;

        return isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode* node1, TreeNode* node2) {
        if(node1 == NULL && node2 == NULL) {
            return true;
        } else if(node1 == NULL || node2 == NULL) {
            return false;
        } else {
            if(node1->val == node2->val) {
                return isSymmetric(node1->left, node2->right) && isSymmetric(node1->right, node2->left);
            } else return false;
        }
    }

    //使用两个栈完成此任务
    bool isSymmetric1(TreeNode* root) {
        if(root == NULL) return true;

        stack<TreeNode* > s1;
        stack<TreeNode* > s2;
        s1.push(root->left);
        s2.push(root->right);

        while (!s1.empty() && !s2.empty()) {
            auto t1 = s1.top();
            auto t2 = s2.top();
            s1.pop();
            s2.pop();

            if(t1 == NULL && t2 == NULL) continue;
            else if(t1 == NULL || t2 == NULL) return false;
            else {
                if(t1->val == t2->val) {
                    s1.push(t1->right);
                    s1.push(t1->left);
                    s2.push(t2->left);
                    s2.push(t2->right);
                } else return false;
            }
        }

        return true;
    }

};

int main() {
    cout << "Hello world" << endl;

    TreeNode* s1 = new TreeNode(1);
    TreeNode* s2 = new TreeNode(2);
    TreeNode* s3 = new TreeNode(2);
    s1->left = s2;
    s1->right = s3;

    Solution* ss = new Solution;
    ss->isSymmetric(s1);

    return 0;
}
