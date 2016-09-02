//
// Created by fengxuan on 2016/9/2.
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

struct Node {
    TreeNode *tmp;
    int num;
    Node(TreeNode* x, int y):tmp(x), num(y) { }
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;

        vector<Node> candidate;
        candidate.push_back(Node(root, root->val));
        int result = 0;

        while (!candidate.empty()) {
            vector<Node> tmp;
            for(auto i = candidate.cbegin(); i != candidate.cend(); ++i) {
                if((*i).tmp->left == NULL && (*i).tmp->right == NULL) result += (*i).num;
                else {
                    TreeNode* l = (*i).tmp->left;
                    if(l != NULL) tmp.push_back(Node(l, ((*i).num * 10 + l->val)));
                    TreeNode* r = (*i).tmp->right;
                    if(r != NULL) tmp.push_back(Node(r, ((*i).num * 10 + r->val)));
                }
            }
            candidate = tmp;
        }

        return result;
    }
};

int main() {
    cout << "Hello world" << endl;

    return 0;
}
