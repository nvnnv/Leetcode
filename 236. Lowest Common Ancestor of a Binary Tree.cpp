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

void ooooxxxx(TreeNode* cur, int x1, int x2, bool& f, TreeNode** LCA)
{
    if (cur == nullptr) return;
    if (cur->val == x1 || cur->val == x2)
    {
        f = true;
    }

    bool fx1 = false;
    if (!(*LCA) && cur->left) ooooxxxx(cur->left, x1, x2, fx1, LCA);
    bool fx2 = false;
    if (!(*LCA) && cur->right) ooooxxxx(cur->right, x1, x2, fx2, LCA);
    if ((f && fx2) || (f && fx1) || (fx1 && fx2))
    {
        if(*LCA == nullptr) *LCA = cur;
    }
    f = f | fx1 | fx2;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    bool f1 = false;
    bool f2 = false;
    TreeNode* LCA = nullptr;
    ooooxxxx(root, p->val, q->val, f1, &LCA);
    return LCA;
}
