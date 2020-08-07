void xoo(TreeNode* cur, int& mi, int& k, int& x, int& _k, bool& openOr)
{
    if(cur == nullptr) return;
    if (mi > cur->val)
    {
        mi = cur->val;
        k = 1;
        x = cur->val;
    }
    if(openOr) xoo(cur->left, mi, k, x, _k, openOr);
    if (k > 0)
    {
        if (k == _k)
        {
            openOr = false;
            x = cur->val;
        }
        ++k;
    }
    if(openOr) xoo(cur->right, mi, k, x, _k, openOr);
}
int kthSmallest(TreeNode* root, int k) {
    int mi = 9999999;
    int kk = -1;
    int x = 0;
    bool o = true;
    xoo(root, mi, kk, x, k, o);
    return x;
}
