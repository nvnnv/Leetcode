void inOrder(TreeNode* cur, vector<int>& v)
{
    if (cur == nullptr) return;
    inOrder(cur->left, v);
    v.push_back(cur->val);
    inOrder(cur->right, v);
}
vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    vector<int> v1;
    inOrder(root1, v1);
    vector<int> v2;
    inOrder(root2, v2);
    if (v1.size() == 0) return v2;
    if (v2.size() == 0)return v1;
    vector<int> v;
    auto i_v2 = v2.begin();
    for (auto i_v1 = v1.begin(); i_v1 != v1.end(); ++i_v1)
    {
        while (i_v2 != v2.end() && *i_v2 <= *i_v1)
        {
            v.push_back(*i_v2);
            ++i_v2;
        }
        v.push_back(*i_v1);
    }
        while (i_v2 != v2.end())
    {
        v.push_back(*i_v2);
        ++i_v2;
    }
    return v;
}
