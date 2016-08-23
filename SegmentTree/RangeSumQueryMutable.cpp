//
// Created by fengxuan on 2016/8/21.
//
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class NumArray {
    struct node {
        int lNum;
        int rNum;
        int value;
        node* left;
        node* right;

        node(int l, int r): lNum(l), rNum(r), left(nullptr), right(nullptr){}
    };

    node *root = nullptr;
public:
    NumArray(vector<int> &nums) {
        if(nums.empty()) return;

        // 为线段树分配内存空间, 线段树的高度, 线段树的最大容量
        root = new node(0, nums.size() - 1);
        root->value = createTree(nums, 0, nums.size() - 1, root);
        root;
    }

    int createTree(vector<int> &nums, int left, int right, node* root) {
        if(left == right) {
            root->value = nums[left];
            return nums[left];
        } else {
            int mid = left + (right - left) / 2;
            node* l1 = new node(left, mid);
            node* r1 = new node(mid + 1, right);
            root->left = l1;
            root->right = r1;

            int tmp = createTree(nums, left, mid, l1) +
            createTree(nums, mid + 1, right, r1);

            root->value = tmp;
            return tmp;
        }
    }

    void update(int i, int val) {
        vector<node *> candidate;

        node* cur = (i >= root->lNum && i <= root->rNum) ? root : NULL;

        while (cur) {
            candidate.push_back(cur);

            int mid = cur->lNum + (cur->rNum - cur->lNum) / 2;

            if(cur->left == NULL && cur->right == NULL) break;
            else if(cur->left != NULL && (i <= mid))
                cur = cur->left;
            else if(cur->right != NULL && (i > mid))
                cur = cur->right;
            else cur = NULL;
        }

        int diff = val - candidate[candidate.size() - 1]->value;

        for(int k = 0; k < candidate.size(); ++k) {
            candidate[k]->value += diff;
        }
    }

    int sumRange(int i, int j) {
        return sum(i, j, root);
    }

    int sum(int i, int j, node* root) {
        if(root->lNum == i && root->rNum == j) return root->value;
        else {
            int mid = root->lNum + (root->rNum - root->lNum) / 2;
            int tmp = 0;

            if(i > mid) {
                tmp = sum(i, j, root->right);
            } else if(j <= mid) {
                tmp = sum(i, j, root->left);
            } else {
                tmp = sum(i, mid, root->left) + sum(mid + 1, j, root->right);
            }

            return tmp;
        }
    }
};

int main() {
    cout << "Hello world" << endl;

    vector<int> tmp = {0, 9, 5, 7, 3};
    NumArray* ss = new NumArray(tmp);
    cout << ss->sumRange(4, 4) << endl;
    cout << ss->sumRange(2, 4) << endl;
    cout << ss->sumRange(3, 3) << endl;
    ss->update(4,5);
    ss->update(1,7);
    ss->update(0,8);
    cout << ss->sumRange(1, 2) << endl;
    ss->update(1,9);
    cout << ss->sumRange(4, 4) << endl;
    ss->update(3, 4);
    //ss->update(1,2);
    //cout << ss->sumRange(0, 2) << endl;

    return 0;
}
