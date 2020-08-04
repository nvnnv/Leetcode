void levelOrder(Node* cur, vector<vector<int>>& v, int level)
{
    if (cur == nullptr) return;
    if (v.size() < level)
    {
        vector<int> vv;
        v.push_back(vv);
    }
    auto& vv = v[level - 1];
    vv.push_back(cur->val);
    for (auto& i : cur->children)
    {
        levelOrder(i, v, level + 1);
    }
}
vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> v;
    levelOrder(root, v, 1);
    return v;
}
