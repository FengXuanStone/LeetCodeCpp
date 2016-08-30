//
// Created by fengxuan on 2016/8/30.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;

        vector<TreeLinkNode* > candidate;
        candidate.push_back(root);

        while(!candidate.empty()) {
            TreeLinkNode* pre = NULL;
            TreeLinkNode* cur = candidate[0];
            vector<TreeLinkNode* > tmp;
            if(cur->left != NULL) tmp.push_back(cur->left);
            if(cur->right != NULL) tmp.push_back(cur->right);


            for(int i = 1; i < candidate.size(); ++i) {
                pre = cur;
                cur = candidate[i];
                pre->next = cur;
                if(cur->left != NULL) tmp.push_back(cur->left);
                if(cur->right != NULL) tmp.push_back(cur->right);
            }

            candidate = tmp;
        }
    }
};

int main() {
    cout << "Hello world" << endl;

    TreeLinkNode* s1 = new TreeLinkNode(1);
    TreeLinkNode* s2 = new TreeLinkNode(2);
    TreeLinkNode* s3 = new TreeLinkNode(3);
    s1->left = s2;
    s1->right = s3;

    Solution* ss = new Solution;
    ss->connect(s1);

    return 0;
}
