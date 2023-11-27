//
// Created by Adam on 2023/11/14.
//
#include "iostream"
#include "stack"
#include "Tree.h"
using namespace std;
class Solution {
public:

    void traversal(TreeNode* root,vector<int> &vec){
        if (root == nullptr)return;
        traversal(root->left,vec);
        vec.push_back(root->val);

        traversal(root->right,vec);

    }
    // 递归
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        traversal(root,vec);
        return vec;
    }
    // 迭代
    vector<int> inorderTraversal1(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) { // 指针来访问节点，访问到最底层
                st.push(cur); // 将访问的节点放进栈
                cur = cur->left;                // 左
            } else {
                cur = st.top(); // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
                st.pop();
                result.push_back(cur->val);     // 中
                cur = cur->right;               // 右
            }
        }
        return result;
    }
    // 统一方法
    class Solution1 {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> result;
            stack<TreeNode*> st;
            if (root != NULL) st.push(root);
            while (!st.empty()) {
                TreeNode* node = st.top();
                if (node != NULL) {
                    st.pop(); // 将该节点弹出，避免重复操作，下面再将右中左节点添加到栈中
                    if (node->right) st.push(node->right);  // 添加右节点（空节点不入栈）

                    st.push(node);                          // 添加中节点
                    st.push(NULL); // 中节点访问过，但是还没有处理，加入空节点做为标记。

                    if (node->left) st.push(node->left);    // 添加左节点（空节点不入栈）
                } else { // 只有遇到空节点的时候，才将下一个节点放进结果集
                    st.pop();           // 将空节点弹出
                    node = st.top();    // 重新取出栈中元素
                    st.pop();
                    result.push_back(node->val); // 加入到结果集
                }
            }
            return result;
        }
    };
};