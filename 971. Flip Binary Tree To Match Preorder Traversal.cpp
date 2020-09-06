void xoxoxoxox(TreeNode* cur, vector<int>& voyage, int& i, vector<int>& a)
{
    if (cur == nullptr) return;
    if (cur->val == voyage[i])
    {
        if (cur->left)
        {
            ++i;
            if (cur->left->val != voyage[i])
            {
                if (cur->right == nullptr)
                {
                    a.clear();
                    a.push_back(-1);
                    return;
                }
                if (cur->right->val == voyage[i])
                {
                    auto t = cur->left;
                    cur->left = cur->right;
                    cur->right = t;
                    a.push_back(cur->val);
                    xoxoxoxox(cur->left, voyage, i, a);
                }
            }
            if (cur->left->val == voyage[i])
            {
                xoxoxoxox(cur->left, voyage, i, a);
            }
        }
        if (cur->right)
        {
            ++i;
            if (cur->right->val == voyage[i])
            {
                xoxoxoxox(cur->right, voyage, i, a);
            }
            else
            {
                a.clear();
                a.push_back(-1);
                return;
            }
        }
    }
    else
    {
        a.clear();
        a.push_back(-1);
    }
}
vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
    if (root == nullptr) return { -1 };
    if (root->val != voyage[0]) return { -1 };
    vector<int> a;
    int i = 0;
    xoxoxoxox(root, voyage, i, a);
    return a;
}
