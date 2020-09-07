void oxo(TreeNode* cur, TreeNode* f, int key, TreeNode** root)
{
    if (cur == nullptr) return;
    if (cur->val > key)
    {
        oxo(cur->left,cur,  key, root);
    }
    if (cur->val < key)
    {
        oxo(cur->right, cur, key, root);
    }
    if (cur->val == key)
    {
        auto left = cur->left;
        auto right = cur->right;
        if (right)
        {
            TreeNode* x = right;
            while (x->left)
            {
                x = x->left;
            }
            x->left = left;
            if (f)
            {
                if (f->left == cur)
                    f->left = right;
                if (f->right == cur)
                    f->right = right;
            }
            else
            {
                *root = right;
            }
        }
        else
        {
            if (f)
            {
                if (f->left == cur)
                    f->left = left;
                if (f->right == cur)
                    f->right = left;
            }
            else
            {
                *root = left;
            }
        }
        delete cur;
        return;
    }
}
TreeNode* deleteNode(TreeNode* root, int key) {
    oxo(root, nullptr, key, &root);
    return root;
}
