TreeNode* increasingBST(TreeNode* root) {
    TreeNode* cRoot = nullptr;
    auto* tc = cRoot;
    if (root == nullptr) return cRoot;
    stack<pair<TreeNode*, int>> v;
    v.push(make_pair(root, 0));
    while (!v.empty())
    {
        auto cur = v.top();
        if (cur.first == nullptr || cur.second == 1)
        {
            if (cur.first != nullptr)
            {
                if (cRoot == NULL)
                {
                    cRoot = new TreeNode(cur.first->val);
                    tc = cRoot;
                }
                else
                {
                    auto* temp = new TreeNode(cur.first->val);
                    tc->right = temp;
                    tc = temp;
                }
            }
            v.pop();
            if (!v.empty())
            {
                auto t = v.top();
                if (t.first == nullptr)
                {
                    continue;
                }
                v.pop();
                if (t.first->right)
                {
                    if (v.empty())
                    {
                        v.push(t);
                        continue;
                    }
                    if (t.first->right == v.top().first) t.second = 1;
                }
                else t.second = 1;
                v.push(t);
            }
            continue;
        }
        v.pop();
        v.push(make_pair(cur.first->right, 0));
        v.push(cur);
        v.push(make_pair(cur.first->left, 0));
    }
    return cRoot;
}
