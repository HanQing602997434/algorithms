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

int maxDepthWithLoop(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    queue<TreeNode*> q;
    q.push(root);
    int depth = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size > 0) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left != NULL) {
                q.push(node->left);
            }
            if (node->right != NULL) {
                q.push(node->right);
            }
            size--;
        }
        depth++;
    }

    return depth;
}