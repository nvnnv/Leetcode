int oox(TreeNode* cur, unordered_map<int, int>& x)
{
    if (cur == nullptr) return 0;
    int a = oox(cur->left, x);
    int b = oox(cur->right, x);
    int y = a + b + cur->val;
    ++x[y];
    return y;
}
vector<int> findFrequentTreeSum(TreeNode* root) {
    unordered_map<int, int> x;
    vector<int> v;
    int y = oox(root, x);
    int m = 0;
    for (auto& p : x)
    {
        if (p.second > m) m = p.second;
    }
    for (auto& p : x)
    {
        if (p.second == m) v.push_back(p.first);
    }
    return v;
}
