void palindronePath(TreeNode* cur, unordered_map<int, int>& path, int& sum)
{
    if (cur->left == nullptr && cur->right == nullptr)
    {
        path[cur->val]++;
        int odd = 0;
        for (auto& p : path)
        {
            if (p.second % 2 != 0) odd++;
        }
        if (odd < 2) sum++;
        path[cur->val]--;
        return;
    }
    path[cur->val]++;
    if (cur->left) palindronePath(cur->left, path, sum);
    if (cur->right) palindronePath(cur->right, path, sum);
    path[cur->val]--;
}
int pseudoPalindromicPaths(TreeNode* root) {
    if (root == nullptr) return 0;
    int sum = 0;
    unordered_map<int, int> p;
    palindronePath(root, p, sum);
    return sum;
}
