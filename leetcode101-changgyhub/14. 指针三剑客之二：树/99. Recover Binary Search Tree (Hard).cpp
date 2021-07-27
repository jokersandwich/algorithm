void recoverTree(TreeNode* root) {
    TreeNode *mistake1 = nullptr, *mistake2 = nullptr, *prev = nullptr;
    inorder(root, mistake1, mistake2, prev);
    if (mistake1 && mistake2) {
        int temp = mistake1 -> val;
        mistake1->val = mistake2->val;
        mistake2->val = temp;
    }
}

void inorder(TreeNode* root, TreeNode*& mistake1, TreeNode*& mistake2, TreeNode*& prev) {
    if (!root) {
        return;
    }
    if (root->left) {
        inorder(root->left, mistake1, mistake2, prev);
    }
    if (prev && root->val < prev->val) {
        if (!mistake1) {
            mistake1 = prev;
            mistake2 = root;
        } else {
            mistake2 = root;
        }
        cout << mistake1->val;
        cout << mistake2->val;
    }
    prev = root;
    if (root->right) {
        inorder(root->right, mistake1, mistake2, prev);
    }
}