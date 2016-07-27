//
// Created by fengxuan on 2016/7/27.
//
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        else if(p == NULL || q == NULL) return false;
        else {
            if(p->val == q->val) {
                return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            } else return false;
        }
    }

    bool isSameTree1(TreeNode* p, TreeNode* q) {
        //tmp
        queue<TreeNode* > pQueue;
        queue<TreeNode* > qQueue;
        pQueue.push(p);
        qQueue.push(q);

        while (!pQueue.empty() || !qQueue.empty()) {
            TreeNode* p1 = pQueue.front();
            TreeNode* q1 = qQueue.front();
            pQueue.pop();
            qQueue.pop();

            if(p1 == NULL && q1 == NULL) continue;
            else if(p1 == NULL || q1 == NULL) return false;
            else {
                if(p1->val != q1->val) return false;
                else {
                    pQueue.push(p1->left);
                    pQueue.push(p1->right);
                    qQueue.push(q1->left);
                    qQueue.push(q1->right);
                }
            }
        }

        return pQueue.empty() && qQueue.empty();
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
