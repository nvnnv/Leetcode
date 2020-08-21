void addRow(TreeNode* cur, int level, int d, int v)
{
    if (cur == nullptr) return;
    if (level + 1 == d) {
        TreeNode* l = new TreeNode(v);
        TreeNode* r = new TreeNode(v);
        auto ll = cur->left;
        auto rr = cur->right;
        l->left = ll;
        r->right = rr;
        cur->left = l;
        cur->right = r;
    }
    addRow(cur->left, level + 1, d, v);
    addRow(cur->right, level + 1, d, v);

}
TreeNode* addOneRow(TreeNode* root, int v, int d) {
    if (root == nullptr)
    {
        return new TreeNode(v);
    }
    if (d == 1)
    {
        TreeNode* x = new TreeNode(v);
        x->left = root;
        return x;
    }
    addRow(root, 1, d, v);
}
