//
// Created by fengxuan on 2016/8/7.
//
#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    struct Money {
        int pre;
        int cur;
        Money():pre(0), cur(0) {}
    };

    int rob(TreeNode* root) {
        Money rootMoney = dfs(root);
        return rootMoney.cur;
    }

    Money dfs(TreeNode* root) {
        if(root == NULL) return Money();

        Money left = dfs(root->left);
        Money right = dfs(root->right);

        Money myMoney;
        myMoney.pre = left.cur + right.cur;
        myMoney.cur = max(myMoney.pre, left.pre + right.pre + root->val);

        return myMoney;
    }

};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
