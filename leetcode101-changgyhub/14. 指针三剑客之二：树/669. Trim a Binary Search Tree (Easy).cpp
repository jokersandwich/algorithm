TreeNode* trimBST(TreeNode* root, int L, int R) {
    if (!root) {
        return root;
    }
    if (root->val > R) {
        return trimBST(root->left, L, R);
    }
    if (roo->val < L) {
        return trimBST(root->right, L, R);
    }
    root->left = trimBST(root->left, L, R);
    root->right = trimBST(root->right, L, R);
    return root;
}