void countTreeNodes(TreeNode* cur, int& x)
{
    if (cur == nullptr) return;
    ++x;
    countTreeNodes(cur->left, x);
    countTreeNodes(cur->right, x);
}
int countNodes(TreeNode* root) {
    int x = 0;
    countTreeNodes(root, x);
    return x;
}
