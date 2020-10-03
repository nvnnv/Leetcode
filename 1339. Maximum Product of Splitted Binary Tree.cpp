    int ee = 1e9 + 7;
int sumTree(TreeNode* cur)
{
    if (cur == nullptr) return 0;
    cur->val += sumTree(cur->left);
    cur->val += sumTree(cur->right);
    return cur->val;
}

int cutONEBranch(TreeNode* cur, TreeNode** root, long long& m)
{
    if (cur == nullptr) return 0;
    int l = cutONEBranch(cur->left, root, m);
    m = max(m, ((long long)l* ((*root)->val - l)));
    int r = cutONEBranch(cur->right, root, m);
    m = max(m, ((long long)r * ((*root)->val - r)));
    return cur->val;
}
int maxProduct(TreeNode* root) {
    sumTree(root);
    long long m = 0;
    cutONEBranch(root, &root, m);
    return m % ee;
}
