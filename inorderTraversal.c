// 二叉树的中序遍历

TreeNode {
    int val;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), parent(NULL), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    accessTree(root, res);
    return res;
}

void accessTree(TreeNode* root, vector<int>& res) {
    if (root == NULL) return;

    accessTree(root->left, res); 
    res.push_back(root->val);
    accessTree(root->right, res);
}

vector<int> inorderTraversalWithLoop(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> stk;
    while (root != NULL || !stk.empty()) {
        while (root != NULL) {
            stk.push(root);
            root = root->left;
        }
        root = stk.pop();
        res.push_back(root->val);
        root = root->right;
    }
    return res;
}