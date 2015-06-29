/**
 * 1. if root is null return 0;
 * 2. check whether left subtree and right subtree is balanced tree
 * 3. check if this level is balanced(no more than 1);
 * 4. update the height
 * */
struct TreeNode
{
    TreeNode * left;
    TreeNode * right;
    int val;
};

bool isBalancedRe(TreeNode * root, int & height)
{
    if (!root)
        return true;
    int leftHeight = 0, rightHeight = 0;
    if (!isBalancedRe(root->left, leftHeight))
        return false;
    if (!isBalancedRe(root->right, rightHeight))
        return false;
    if (abs(leftHeight - rightHeight) > 1)
        return false;
    height = max(leftHeight, rightHeight) + 1;
    return true;
}

bool isBalanced(TreeNode * root)
{
    int height = 0;
    return isBalancedRe(root, height);
}
