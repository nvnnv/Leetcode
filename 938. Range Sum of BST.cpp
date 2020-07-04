// loop traversal of tree
int rangeSumBST(TreeNode* root, int L, int R) {
    stack<pair<TreeNode*,int>> s;
    s.push(make_pair(root,0));
    int ss = 0;
    while (!s.empty())
    {
        auto& cur = s.top();
        if (cur.first == NULL|| cur.second ==3)
        {
            s.pop();
            continue;
        }
        if (cur.first->val >= L &&cur.first->val <= R)
        {
            ss += (cur.first->val);
            cur.second = 3;
            s.push(make_pair(cur.first->left, 0));
            s.push(make_pair(cur.first->right, 0));
        }
        if (cur.first->val < L)
        {
            cur.second = 3;
            s.push(make_pair(cur.first->right, 0));
        }
        if (cur.first->val > R)
        {
            cur.second = 3;
            s.push(make_pair(cur.first->left, 0));
        }
    }
    return ss;
}

//    recursion version
    void xxoo(TreeNode* cur, int L, int R, int& s)
{
    if (cur == NULL) return;
    if (cur->val >= L && cur->val <= R)
    {
        s += cur->val;
        xxoo(cur->left, L, R, s);
        xxoo(cur->right, L, R, s);
    }
    if (cur->val < L)
    {
        xxoo(cur->right, L, R, s);
    }
    if (cur->val > R)
    {
        xxoo(cur->left, L, R, s);
    }
}
