TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty()) {
        return nullptr;
    }
    unordered_map<int, int> hash;
    for (int i = 0; i < preorder.size(); ++i) {
        hash[inorder[i]] = i;
    }
    return buildTreeHelper(hash, preorder, 0, preorder.size() - 1, 0);
}

TreeNode* buildTreeHelper(unordered_map<int, int> & hash, vector<int>& preorder, int s0, int e0, int s1) {
    if (s0 > e0) {
        return nullptr;
    }
    int mid = preorder[s1], index = hash[mid], leftLen = index - s0 - 1;
    TreeNode* node = new TreeNode(mid);
    node->left = buildTreeHelper(hash, preorder, s0, index - 1, s1 + 1);
    node->right = buildTreeHelper(hash, preorder, index + 1, e0, s1 + 2 + leftLen);
    return node;
}