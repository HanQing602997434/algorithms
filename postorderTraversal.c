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

vector<int> postorderTraversalWithLoop(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> stk;
    TreeNode* prevAccess = NULL;
    while (root != NULL || !stk.empty()) {
        while (root != NULL) {
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        if (root->right == NULL || root->right == prevAccess) {
            res.push_back(root->val);
            prevAccess = root;
            root = NULL;
        }
        else {
            stk.push(root);
            root = root->right;
        }
    }
}