// 二叉树的最大深度
#include <algorithm>

TreeNode {
    int val;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;
};

int maxDepth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    else {
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
}