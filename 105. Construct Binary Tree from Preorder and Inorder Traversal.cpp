TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& i, int& j, bool& t, unordered_set<int>& s)
{
    TreeNode* cur = new TreeNode(preorder[i]);
    s.insert(cur->val);
    bool f = true;
    while (i < preorder.size()-1 &&preorder[i] != inorder[j])
    {
        ++i;
        auto node = _buildTree(preorder, inorder, i, j, f, s);
        if (f) cur->left = node;
        else cur->right = node;
        if (!f) return cur;
        if(j+1 < inorder.size() && s.count(inorder[j+1]))
        {
            ++j;
            return cur;
        }
        if(j < inorder.size()) ++j;
        f = !f;
    }
    if (i < preorder.size() - 1 && preorder[i] == inorder[j])
    {
        if (j+1 < inorder.size() &&!s.count(inorder[j+1]))
        {
            ++i;++j;
            bool f = true;
            auto node = _buildTree(preorder, inorder, i, j, f, s);
            cur->right = node;
        }
        else
        {
            ++j;
        }
    }
    return cur;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.size() == 0 || inorder.size() == 0) return nullptr;
    int i = 0, j = 0;
    bool f = 0;
    unordered_set<int> s;
    return _buildTree(preorder, inorder, i, j, f, s);
}
