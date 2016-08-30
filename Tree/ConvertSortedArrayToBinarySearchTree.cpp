//
// Created by fengxuan on 2016/8/28.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        if(nums.size() == 1) return new TreeNode(nums[0]);

        int begin = 0;
        int end = nums.size();

        int mid = begin + (end - begin) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = create(nums, begin, mid);
        root->right = create(nums, mid + 1, end);

        return root;
    }

    TreeNode* create(vector<int>& nums, int begin, int end) {
        if(begin >= end) return NULL;
        if(begin + 1 == end) {
            TreeNode *leaf = new TreeNode(nums[begin]);
            return leaf;
        }

        int mid = begin + (end - begin) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = create(nums, begin, mid);
        node->right = create(nums, mid + 1, end);

        return node;
    }
};

int main() {
    cout << "Hello world" << endl;


    return 0;
}
