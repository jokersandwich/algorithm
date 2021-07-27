int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    helper(root, diameter);
    return diameter;
}

int helper(TreeNode* node, int& diameter) {
    if (!node) {
        return 0;
    }
    int l = helper(node->left, diameter), r = helper(node->right, diameter);
    diameter = max(l + r, diameter);
    return max(l, r) + 1;
}

// javascript
/**
 * @param {TreeNode} root
 * @return {number}
 */
// var diameterOfBinaryTree = function(root) {
//     let diameter = 0;
//     function depth(r) {
//         if (!r) return 0;
//         const left = depth(r.left);
//         const right = depth(r.right);
//         diameter = Math.max(diameter, left + right);
//         return 1 + Math.max(left, right);
//     }
//     depth(root)
//     return diameter;
// };