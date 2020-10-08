pair<long long, long long> isBST(TreeNode* cur, bool& f)
{
    if (cur->left==nullptr && cur->right==nullptr) return {cur->val,cur->val};
    // (a, b)  a=min  b =max
    pair<long long, long long>  l = {cur->val, (long long)cur->val-1};
    if (cur->left)
    {
        l = isBST(cur->left, f);
    }
    pair<long long, long long>  r = { (long long)cur->val+1, cur->val };
    if (cur->right)
    {
        r = isBST(cur->right, f);
    }
    if (cur->val > l.second && cur->val < r.first)
    {

    }
    else
    {
        f = false;
    }
    return { l.first, r.second };
}
bool isValidBST(TreeNode* root) {
    if (root == nullptr) return true;
    bool f = true;
    isBST(root, f);
    return f;
}
