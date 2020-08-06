void xo(TreeNode* cur, int level, int& deep, int& x)
{
    if (cur == nullptr) return;
    if (level > deep)
    {
        deep = level; x = cur->val;
    }
    xo(cur->left, level + 1, deep, x);
    xo(cur->right, level + 1, deep, x);
}
int findBottomLeftValue(TreeNode* root) {
    int a = 0;
    int b = 0;
    xo(root, 1, a, b);
    return b;
}


int findBottomLeftValue(TreeNode* root) {
    vector<tuple<TreeNode*, int, int, int>> v;
    v.push_back(make_tuple(root, 0, 1, -1));
    int maxDeep = 0;
    int ans = 0;
    while (!v.empty())
    {
        auto cur = v.back();
        if (get<1>(cur) == 1)
        {
            if (get<2>(cur) > maxDeep)
            {
                maxDeep = get<2>(cur);
                ans = get<0>(cur)->val;
            }
            v.pop_back();
            continue;
        }
        auto node = get<0>(cur);
        int deep = get<2>(cur)+1;
        v.pop_back();
        if (node->right) v.push_back(make_tuple(node->right, 0, deep, v.size()+1));
        get<1>(cur) = 1;
        v.push_back(cur);
        if(node->left) v.push_back(make_tuple(node->left, 0, deep, v.size() - 1));
    }
    return ans;
}
