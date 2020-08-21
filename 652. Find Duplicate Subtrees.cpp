    stringstream ss;
string findSubtree(TreeNode* cur, unordered_map<string, int>& x, unordered_map<string, TreeNode*>& y)
{
    if (cur == nullptr) return " ";
    auto l = findSubtree(cur->left, x, y);
    auto r = findSubtree(cur->right, x, y);
    ss.clear();
    string val;
    ss << cur->val;
    ss >> val;
    val += "|";
    val += l + r;
    x[val]++;
    y[val] = cur;
    return val;
}
vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    unordered_map<string, int> x;
    unordered_map<string, TreeNode*> y;
    findSubtree(root, x, y);
    vector<TreeNode*> ans;
    for (auto& p : x)
    {
        if (p.second > 1)
        {
            ans.push_back(y[p.first]);
        }
    }
    return ans;
}
