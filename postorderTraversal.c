// 二叉树的后序遍历

TreeNode {
    int val;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    accessTree(root, res);
    return res;
}

void accessTree(TreeNode* root, vector<int>& res) {
    if (root == NULL) return;
    accessTree(root->left);
    accessTree(root->right);
    res.push_back(root->val);
}