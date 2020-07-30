void deleteT(TreeNode* cur, TreeNode* curP, set<int>& to, vector<TreeNode*>& xo)
{
    if (cur == nullptr) return;
    if (to.count(cur->val))
    {
        if (cur->left && !to.count(cur->left->val)) xo.push_back(cur->left);
        if (cur->right && !to.count(cur->right->val)) xo.push_back(cur->right);
        if (curP)
        {
            if (curP->left == cur) curP->left = nullptr;
            else curP->right = nullptr;
        }
        //delete cur;
    }
    deleteT(cur->left, cur, to, xo);
    deleteT(cur->right, cur, to, xo);
}
vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    vector<TreeNode*> po;
    set<int> x;
    for (auto i : to_delete)
    {
        x.insert(i);
    }
    if(!x.count(root->val)) po.push_back(root);
    deleteT(root,nullptr, x, po);
    return po;
}
