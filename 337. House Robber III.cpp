void getMax$(TreeNode* cur, unordered_map<int,int>& m, int& x)
{
    if (cur->left == nullptr && cur->right == nullptr)
    {
        m[cur->val] = cur->val;
        x = max(x, m[cur->val]);
        return;
    }
    int ll = 0, lr = 0, l = 0;
    if (cur->left)
    {
        getMax$(cur->left, m,x);
        if (cur->left->left)
        {
            ll = m[cur->left->left->val];
        }
        if (cur->left->right)
        {
            lr = m[cur->left->right->val];
        }
        l = m[cur->left->val];
    }
    int rl = 0, rr = 0, r = 0;
    if (cur->right)
    {
        getMax$(cur->right, m,x);
        if (cur->right->left)
        {
            rl = m[cur->right->left->val];
        }
        if (cur->right->right)
        {
            rr = m[cur->right->right->val];
        }
        r = m[cur->right->val];
    }
    int t = max(cur->val + ll + lr + rl + rr, l + r);
    t = max(t, r + ll + lr);
    t = max(t, l + rr + rl);
    m[cur->val] = t;
    x = max(x, m[cur->val]);
}
int rob(TreeNode* root) {
    if(root == nullptr) return 0;
    int m = 0;
    unordered_map<int, int> mmmm;
    getMax$(root, mmmm, m);
    return m;
}
