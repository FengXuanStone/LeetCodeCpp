//
// Created by fengxuan on 2016/8/30.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <string.h>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        stack<TreeNode* > help;

        if(root == NULL) return;
        TreeNode* p = root;

        while (!help.empty() || p != NULL) {
            while (p != NULL) {
                help.push(p);
                p = p->left;
            }

            if(!help.empty()) {
                p = help.top();
                help.pop();
                candidate.push_back(p);
                p = p->right;
            }
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return index < candidate.size();
    }

    /** @return the next smallest number */
    int next() {
        return candidate[index++]->val;
    }

private:
    vector<TreeNode *> candidate;
    int index = 0;
};

int main() {
    cout << "Hello world" << endl;

    strcmp("a","v");

    return 0;
}
