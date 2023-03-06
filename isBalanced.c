// 平衡二叉树

TreeNode {
    int val;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;
}

bool isBalanced(TreeNode* root) {
    if (root == NULL) {
        return true;
    }

    return helper(root) != -1;
}

bool helper(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int left = helper(root->left);
    int right = helper(root->right);
    if (left == -1 || right == -1 || abs(left - right) > 1) {
        return -1;
    }

    return max(left, right) + 1;
}