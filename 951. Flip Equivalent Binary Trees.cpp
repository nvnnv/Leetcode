bool flipxx(TreeNode* r1, TreeNode* r2)
{
    if (r1 == nullptr && r2 == nullptr)
    {
        return true;
    }

    if (r1 && r2)
    {
        if (r1->val == r2->val)
        {
            return (flipxx(r1->left, r2->left) && flipxx(r1->right, r2->right)) || (flipxx(r1->left, r2->right) && flipxx(r1->right, r2->left));
        }
    }
    return false;
}
bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    return flipxx(root1, root2);
}
