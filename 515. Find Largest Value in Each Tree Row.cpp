void xxo(TreeNode* cur, int level, vector<int>& x)
{
    if (cur == nullptr) return;
    if (level > x.size())
    {
        x.push_back(cur->val);
    }
    else
    {
        auto& m = x[level - 1];
        if (m < cur->val) m = cur->val;
    }
    xxo(cur->left, level + 1, x);
    xxo(cur->right, level + 1, x);
}
vector<int> largestValues(TreeNode* root) {
    vector<int> level;
    xxo(root, 1, level);
    return level;
}
