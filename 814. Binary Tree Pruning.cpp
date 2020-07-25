void cut0(TreeNode* cur, TreeNode* curP, bool& f0, TreeNode** root)
{
    if (cur == nullptr)
    {
        f0 = false;
        return;
    }
    bool fl = true;
    cut0(cur->left,cur, fl, root);
    bool fr = true;
    cut0(cur->right,cur, fr, root);
    if (fl || fr)
    {
        f0 = true;
    }
    else
    {
        if (cur->val == 1)
        {
            cur->left = nullptr;
            cur->right = nullptr;
            f0 = true;
        }
        else
        {
            if (cur == *root)
            {
                *root = nullptr;
            }
            if (curP->left == cur) curP->left = nullptr;
            else curP->right = nullptr;
            f0 = false;
        }

    }
}
TreeNode* pruneTree(TreeNode* root) {
    bool f = true;
    cut0(root, nullptr, f, &root);
    return root;
}
