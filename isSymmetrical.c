// 对称二叉树

// 给定一个二叉树，检查它是否是镜像对称的。

TreeNode {
    int val;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), parent(NULL), left(NULL), right(NULL) {}
}

bool isSymmetrical(TreeNode* root) {
    if (root == NULL) return true;

    // 调用递归函数，比较左节点，右节点
    return deepCheck(root->left, root->right);
}

bool deepCheck(TreeNode* left, TreeNode* right) {
    // 递归的终止条件是两个节点都为空
    // 或者两个节点中有一个为空
    // 或者两个节点值不相等
    if (left == NULL && right == NULL) return true;

    if (left == NULL || right == NULL) return false;

    if (left->val != right->val) return false;

    // 再递归的比较，左节点的左孩子 和 右节点的右孩子
    // 以及比较 左节点的右孩子 和 右节点的左孩子
    return deepCheck(left->left, right->right) && deepCheck(left->right, right->left);
}

bool isSymmetricalWithLoop(TreeNode* root) {
    if (root == NULL) {
        return false;
    }

    queue<TreeNode*> q;
    u = root->left;
    v = root->right;
    if (u == NULL && v == NULL) {
        return true;
    }

    q.push(u);
    q.push(v);

    while (!q.empty()) {
        u = q.front();
        q.pop();
        v = q.front();
        q.pop();

        if (u == NULL  && v == NULL) {
            continue;
        }

        if ((u == NULL || v == NULL) || (u->val != v->val)) {
            return false;
        }

        q.push(u->left);
        q.push(v->right);
        q.push(u->right);
        q.push(v->left);
    }

    return true;
}