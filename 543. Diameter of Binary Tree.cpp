// loop 24ms
int diameterOfBinaryTree(TreeNode* root) {
    if (root == nullptr) return 0;
    int level = 0;
    int ans = 0;
    vector<tuple<TreeNode*, int, int, int, int>> v;
    v.push_back(make_tuple(root, 0, 0, 0, -1));
    while (!v.empty())
    {
        auto& cur = v.back();
        if ((get<0>(cur)->left == nullptr && get<0>(cur)->right == nullptr) || get<3>(cur) == 1)
        {
            if (get<4>(cur) != -1)
            {
                auto& dad = v[get<4>(cur)];
                get<3>(dad) = 1;
                if (get<0>(dad)->left == get<0>(cur))
                {
                    get<1>(dad) = max(get<1>(cur)+1, get<2>(cur)+1);
                }
                if (get<0>(dad)->right == get<0>(cur))
                {
                    get<2>(dad) = max(get<1>(cur) + 1, get<2>(cur) + 1);
                }
            }
            ans = max(ans, get<1>(cur));
            ans = max(ans, get<2>(cur));
            ans = max(ans, get<1>(cur) + get<2>(cur));
            v.pop_back();
            continue;
        }
        int dadpos = v.size() - 1;
        auto node = get<0>(cur);
        if (node->left) v.push_back(make_tuple(node->left, 0, 0, 0, dadpos));
        if (node->right) v.push_back(make_tuple(node->right, 0, 0, 0, dadpos));
    }
    return ans;
}

// recursion remend 16ms
void oxxxx(TreeNode* cur, int& level, int& ans)
{
    if (cur->left == NULL && cur->right == NULL)
    {
        level++;
        return;
    }
    int left = 0;
    if (cur->left)
    {
        ++left;
        oxxxx(cur->left,left,ans);
    }
    int right = 0;
    if (cur->right)
    {
        ++right;
        oxxxx(cur->right,right,ans);
    }
    level = max(right, left)+level;
    ans = max(ans, left+right-1-1);
    ans = max(ans, level-1);
}
int diameterOfBinaryTree(TreeNode* root) {
    if (root == nullptr) return 0;
    int level = 0;
    int ans = 0;
    oxxxx(root, level, ans);
    return ans;
}

// recursion 212ms
void oxxxx(TreeNode* cur, vector<vector<TreeNode*>>& allPaths, vector<TreeNode*>& v)
{
    if (cur->left == NULL && cur->right == NULL)
    {
        vector<TreeNode*> vv = v;
        vv.push_back(cur);
        allPaths.push_back(vv);
        return;
    }
    if (cur->left)
    {
        v.push_back(cur);
        oxxxx(cur->left, allPaths, v);
        v.pop_back();
    }
    if (cur->right)
    {
        v.push_back(cur);
        oxxxx(cur->right, allPaths, v);
        v.pop_back();
    }
}
int diameterOfBinaryTree(TreeNode* root) {
    if (root == nullptr) return 0;
    vector<vector<TreeNode*>> aP;
    vector<TreeNode*> v;
    oxxxx(root, aP, v);
    int ans = 0;
        if (aP.size() == 1)
    {
        return aP[0].size()-1;
    }
    for (int i =0;i<aP.size();++i)
    {
        auto& s = aP[i];
        for (int j = 0; j < aP.size(); ++j)
        {
            if (i == j) continue;
            auto& other = aP[j];
            int k = 0;
            while (k < s.size() && k < other.size())
            {
                if (s[k] != other[k]) break;
                ++k;
            }
            ans = max(ans, (int)(s.size() - k + other.size() - k));
        }
        ans = max(ans, (int)s.size() - 1);
    }
    return ans;
}
