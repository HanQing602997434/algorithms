// 二叉树的前序遍历

TreeNode {
    int val;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), parent(NULL), left(NULL), right(NULL) {}
};

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    accessTree(root, res);
    return res;
}

void accessTree(TreeNode* root, vector<int>& res) {
    if (root == NULL) return;
    res.push_back(root->val);
    accessTree(root->left);
    accessTree(root->right);
}