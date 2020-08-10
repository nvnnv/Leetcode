void _levelOrder(TreeNode* cur, int level, vector<vector<int>>& v)
{
    if (cur == nullptr) return;
    if (level == v.size())
    {
        vector<int> vv;
        v.push_back(vv);
    }
    v[level].push_back(cur->val);
    _levelOrder(cur->left, level + 1, v);
    _levelOrder(cur->right, level + 1, v);
}
vector<int> rightSideView(TreeNode* root) {
    vector<vector<int>> v;
    _levelOrder(root, 0, v);
    vector<int> right;
    for (auto& i : v)
    {
        right.push_back(i.back());
    }
    return right;
}
