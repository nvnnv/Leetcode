int findMinDiff(TreeNode* cur, int v)
{
    if (cur == nullptr) return 999999;
    if (cur->val < v) return 999999;
    int x = (findMinDiff(cur->left, v), findMinDiff(cur->right, v));
    return min(x, cur->val - v);
}
void insertMaxTree(TreeNode* cur, int v, int x, TreeNode** root)
{
    if (cur == nullptr) return;
    if(cur->val == v)
    {
        TreeNode* node = new TreeNode(x);
        node->left = cur->right;
        cur->right = node;
    }
    else
    {
        insertMaxTree(cur->left, v, x, root);
        insertMaxTree(cur->right, v, x, root);
    }
}
TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
    int x = findMinDiff(root, val);
    if (x == 999999)
    {
        TreeNode* node = new TreeNode(val);
        node->left = root;
        root = node;
    }
    else insertMaxTree(root, x + val, val, &root);
    return root;
}
