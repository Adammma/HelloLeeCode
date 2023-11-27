//
// Created by Adam on 2023/11/14.
//

#ifndef HELLOLEECODE_TREE_H
#define HELLOLEECODE_TREE_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif //HELLOLEECODE_TREE_H
