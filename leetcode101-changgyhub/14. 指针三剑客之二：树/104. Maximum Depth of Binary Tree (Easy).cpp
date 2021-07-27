int maxDepth(TreeNode& root) {
    return root? 1 + max(maxDepth(root->left), maxDepth(root->right)): 0;
}

// javascript
/**
 * @param {TreeNode} root
 * @return {number}
 */
// var maxDepth = function(root) {
//     if (!root) return 0;
//     return 1 + Math.max(maxDepth(root.left), maxDepth(root.right));
// };