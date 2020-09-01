void ooooxxxx(TreeNode* cur, int x ,bool& f, vector<TreeNode*>& v)
{
    if (cur == nullptr) return;
    if (cur->val == x)
    {
        v.push_back(cur);
        f = true;
        return;
    }
    v.push_back(cur);
    if (!f && cur->left) ooooxxxx(cur->left, x, f, v);
    if (!f && cur->right) ooooxxxx(cur->right, x, f, v);
    if (!f) v.pop_back();

}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    bool f = false;
    vector<TreeNode*> pp;
    ooooxxxx(root, p->val, f, pp);
    f = false;
    vector<TreeNode*> qq;
    ooooxxxx(root, q->val, f, qq);
    unordered_set<int> x;
    for (auto& i : pp)
    {
        x.insert(i->val);
    }
    for (auto it = qq.rbegin(); it != qq.rend(); ++it)
    {
        if (x.count((*it)->val))
        {
            return *it;
        }
    }
    return nullptr;
}
