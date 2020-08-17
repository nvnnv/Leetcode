void PathSameVal(TreeNode* cur, int& same, int& x)
{
    if (cur->left == nullptr && cur->right == nullptr)
    {
        x = 1;
        same = max(x, same);
        return;
    }
    int left = 0;
    if (cur->left)
    {
        PathSameVal(cur->left, same, left);
        if (cur->val == cur->left->val)
        {
            left++;
        }
        else
        {
            left = 0;
        }
    }
    int right = 0;
    if (cur->right)
    {
        PathSameVal(cur->right, same, right);
        if (cur->val == cur->right->val)
        {
            right++;
        }
        else
        {
            right = 0;
        }
    }
    if (left == 0 && right == 0)
    {
        x = 1;
    }
    if (left && right == 0)
    {
        x = left;
    }
    if (left == 0 && right)
    {
        x = right;
    }
    if (left && right)
    {
        x = max(left, right);
        if (cur->left->val == cur->val && cur->right->val == cur->val)
        {
            same = max(left + right - 1, same);
        }
    }
    same = max(x, same);
}
int longestUnivaluePath(TreeNode* root) {
    if(root == nullptr) return 0;
    int same = 0;
    int x = 0;
    PathSameVal(root, same, x);
    return same-1;
}
