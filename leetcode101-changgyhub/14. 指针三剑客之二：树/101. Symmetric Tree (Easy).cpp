bool isSymmetric(TreeNode *root) {
    return root? isSymmetric(root->left, root->right): true;
}

bool isSymmetric(TreeNode* left, TreeNode* right) {
    if (!left && !right) {
        return true;
    }
    if (!left || !right) {
        return false;
    }
    if (left->val != right->val) {
        return false;
    }
    return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
}

// javascript
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
// var isSymmetric = function(root) {
//     if (!root) return;
//     return _isSymmetric(root.left, root.right);
// };

// function _isSymmetric(left, right) {
//     if (!left && !right) {
//         return true;
//     }
//     if (!left || !right) {
//         return false;
//     }
//     if (left.val !== right.val) {
//         return false;
//     }
//     return _isSymmetric(left.left, right.right) && _isSymmetric(left.right, right.left);
// }