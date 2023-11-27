//
// Created by Adam on 2023/11/16.
//
#include "iostream"

using namespace std;

#include "Tree.h"
#include "queue"

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        queue<TreeNode *> que;
        if (root != NULL)
            que.push(root);
        vector<vector<int>> res;
        while (!que.empty()) {
            vector<int> tmp;
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *node = que.front();
                que.pop();
                tmp.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};