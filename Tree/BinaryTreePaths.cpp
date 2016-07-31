//
// Created by fengxuan on 2016/7/31.
//
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;

        if(root == NULL)
            return result;

        vector<vector<TreeNode*>> candidate;
        candidate.push_back( vector<TreeNode*>{root} );

        while (!candidate.empty()) {
            vector<vector<TreeNode*>> tmp;

            for(int i = 0; i < candidate.size(); ++i) {
                auto x = candidate[i];
                auto last = x.end() - 1;

                if((*last)->left == NULL && (*last)->right == NULL) {
                    ostringstream oss;
                    int j = 0;
                    for(; j < x.size() - 1; ++j) {
                        oss << x[j]->val << "->";
                    }
                    oss << x[j]->val;
                    string s = oss.str();
                    result.push_back(s);
                } else {
                    if((*last)->left != NULL) {
                        vector<TreeNode*> s(x);
                        s.push_back((*last)->left);
                        tmp.push_back(s);
                    }
                    if((*last)->right != NULL) {
                        vector<TreeNode*> s(x);
                        s.push_back((*last)->right);
                        tmp.push_back(s);
                    }
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
