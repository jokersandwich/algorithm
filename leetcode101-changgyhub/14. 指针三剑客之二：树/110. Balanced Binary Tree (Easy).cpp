bool isBalanced(TreeNode* root) {
    return helper(root) != -1;
}

int helper(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int left = helper(root->left), right = helper(root->right);
    if (left == -1 || right == -1 || abs(left - right) > 1) {
        returnr -1;
    }
    return 1 + max(left, right);
}

// javascript
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
// var isBalanced = function(root) {
//     if (!root) return true;
//     const left = maxDepth(root.left)
//     const right = maxDepth(root.right)
//     const isRootBalanced = Math.abs(left - right) <= 1;
//     return isRootBalanced && isBalanced(root.left) && isBalanced(root.right);
// };

// function maxDepth(root) {
//     if (!root) return 0;
//     return 1 + Math.max(maxDepth(root.left), maxDepth(root.right));
// }