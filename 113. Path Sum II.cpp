void xxxxooo(TreeNode* cur, int s, int& su, vector<int>& t1, vector<vector<int>>& t)
{
    if (cur->left == nullptr && cur->right == nullptr)
    {
        if (s + cur->val == su)
        {
            t1.push_back(cur->val);
            t.push_back(t1);
            t1.pop_back();
        }
    }
    if (cur->left)
    {
        t1.push_back(cur->val);
        xxxxooo(cur->left, s + cur->val, su, t1, t);
        t1.pop_back();
    }
    if (cur->right)
    {
        t1.push_back(cur->val);
        xxxxooo(cur->right, s + cur->val, su, t1, t);
        t1.pop_back();
    }
}
vector<vector<int>> pathSum(TreeNode* root, int sum) {
    if (root == nullptr) return {};
    vector<vector<int>> t; vector<int> t1;
    xxxxooo(root, 0, sum, t1, t);
    return t;
}
