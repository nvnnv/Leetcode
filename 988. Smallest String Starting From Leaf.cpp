void xxxoooo(TreeNode* cur, string& x, string& wewant)
{
    if (cur->left == nullptr && cur->right == nullptr)
    {
        x.push_back(cur->val + 'a');
        string s = x;
        reverse(s.begin(), s.end());
        if (s < wewant) wewant = s;
        x.pop_back();
        return;
    }
    x.push_back(cur->val + 'a');
    if (cur->left)
    {
        xxxoooo(cur->left, x, wewant);
    }
    if (cur->right)
    {
        xxxoooo(cur->right, x, wewant);
    }
    x.pop_back();
}
string smallestFromLeaf(TreeNode* root) {
    if (root == nullptr) return "";
    string x = "";
    string wewant = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    xxxoooo(root, x, wewant);
    return wewant;
}
