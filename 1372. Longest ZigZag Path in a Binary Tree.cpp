void _zigZag(TreeNode* cur, int direct,int length, int& biggest)
{
    if (cur == nullptr)
    {
        return;
    }
    if (direct == 1)
    {
        _zigZag(cur->left, 0, length + 1, biggest);
        _zigZag(cur->right, 1, 1, biggest);
    }
    if (direct == 0)
    {
        _zigZag(cur->right, 1, length + 1, biggest);
        _zigZag(cur->left, 0, 1, biggest);
    }
    biggest = max(length, biggest);
}
int longestZigZag(TreeNode* root) {
    int big = 0;
    _zigZag(root, 1, 0, big);
    return big;
}
