vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    vector<TreeNode*> forest;
    unordered_set<int> dict(to_delete.begin(), to_delete.end());
    root = helper(root, dict, forest);
    if (root) {
        forest.push_back(root);
    }
    return forest;
}

TreeNode* helper(TreeNode* root, unordered_set<int> & dict, vector<TreeNode*> & forest) {
    if (!root) {
        return root;
    }
    root->left = helper(root->left, dict, forest);
    root->right = helper(root->right, dict, forest);
    if (dict.count(root->val)) {
        if (root->left) {
            forest.push_back(root->left);
        }
        if (root->right) {
            forest.push_back(root->right);
        }
        root = NULL;
    }
    return root;
}