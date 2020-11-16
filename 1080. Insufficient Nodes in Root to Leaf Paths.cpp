int cropTreeBySum(TreeNode* cur, int sum, int& limit)
{
    if (cur->left == nullptr && cur->right == nullptr) return sum + cur->val;
    int ls = -1000000; int lr = -1000000;
    if (cur->left)
    {
        ls = cropTreeBySum(cur->left, sum + cur->val, limit);
        if (ls < limit)
        {
            cur->left = nullptr;
        }
    }
    if (cur->right)
    {
        lr = cropTreeBySum(cur->right, sum + cur->val, limit);
        if (lr < limit)
        {
            cur->right = nullptr;
        }
    }
    return max(ls, lr);
}
TreeNode* sufficientSubset(TreeNode* root, int limit) {
    int s = cropTreeBySum(root, 0, limit);
    if (s < limit) root = nullptr;
    return root;
}
