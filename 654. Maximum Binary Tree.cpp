// iteration method is slow..... 216ms
TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    if (nums.size() == 0) return nullptr;
    TreeNode* root = nullptr;
    vector<tuple<int,int,int, int, int, TreeNode*, TreeNode*>> v;
    v.push_back(make_tuple(0, nums.size() - 1,0, -1, 0, nullptr, nullptr));
    while (!v.empty())
    {
        auto& cur = v.back();
        if (get<0>(cur) == get<1>(cur) || get<2>(cur))
        {
            TreeNode* x = nullptr;
            if (!get<2>(cur))x = new TreeNode(nums[get<0>(cur)]);
            else x = new TreeNode(get<4>(cur));
            x->left = get<5>(cur);
            x->right = get<6>(cur);
            if (get<3>(cur) != -1)
            {
                auto& dad = v[get<3>(cur)];
                get<2>(dad) = 1;
                if (get<0>(cur) == get<0>(dad)) get<5>(dad) = x;
                if (get<1>(cur) == get<1>(dad)) get<6>(dad) = x;
            }
            else
            {
                root = x;
            }
            v.pop_back();
            continue;
        }
        int m = 0;
        int m_i = 0;
        int i = get<0>(cur);
        int j = get<1>(cur);
        for (int x=i; x <= j; ++x)
        {
            if (m <= nums[x])
            {
                m = nums[x]; m_i = x;
            }
        }
        get<4>(cur) = m;
        int dadpos = v.size() - 1;
        if (i < m_i) v.push_back(make_tuple(i, m_i - 1, 0, dadpos, 0, nullptr, nullptr));
        if (m_i < j) v.push_back(make_tuple(m_i + 1, j, 0, dadpos, 0, nullptr, nullptr));
    }
    return root;
}

// recursion 108ms
TreeNode* ConMaxTree(vector<int>& v, int i, int j)
{
    int m = 0;
    int m_i;
    for (int x = i; x <= j; ++x)
    {
        if (m <= v[x])
        {
            m = v[x];
            m_i = x;
        }
    }
    TreeNode* xo = new TreeNode(m);
    if (i < m_i)
    {
        xo->left = ConMaxTree(v, i, m_i - 1);
    }
    if (m_i < j)
    {
        xo->right = ConMaxTree(v, m_i + 1, j);
    }
    return xo;
}
TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    if (nums.size() == 0) return nullptr;
    return ConMaxTree(nums, 0, nums.size() - 1);
}
