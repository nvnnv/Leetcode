void getDeepestNode(TreeNode* cur, int deep, int& deepest, int& sum)
{
    
    if (cur->left == nullptr && cur->right == nullptr)
    {
        if (deep == deepest)
        {
            sum += cur->val;
        }
        if (deep > deepest)
        {
            sum = cur->val;
            deepest= deep;
        }
        return;
    }
    deepest = max(deep, deepest);
    if (cur->left) getDeepestNode(cur->left, deep + 1, deepest, sum);
    if (cur->right) getDeepestNode(cur->right, deep + 1, deepest, sum);
}
int deepestLeavesSum(TreeNode* root) {
    if (root == nullptr) return 0;
    int deepest = 0;
    int sum = 0;
    getDeepestNode(root, 0, deepest, sum);
    return sum;
}
