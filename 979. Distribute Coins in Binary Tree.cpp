int distribute(TreeNode* cur, int& sum)
{
    if (cur == nullptr) return 0;
    int left = distribute(cur->left, sum);
    int right = distribute(cur->right, sum);
    sum += abs(left) + abs(right);
    return cur->val + left + right - 1;
}
int distributeCoins(TreeNode* root) {
    int sum = 0;
    distribute(root, sum);
    return sum;
}
