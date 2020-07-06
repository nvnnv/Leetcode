bool isUnivalTree(TreeNode* root) {
    if (root == nullptr)
    {
        return true;
    }
    unordered_set<int> f;
    vector<tuple<TreeNode*, TreeNode*, TreeNode*,int>> v; // ndoe, flag of left subtree, flag of right subtree, index of dad
    v.push_back(make_tuple(root, nullptr, nullptr,-1));
    while (!v.empty())
    {
        auto& cur = v.back();
        if (get<1>(cur) == get<0>(cur)->left && get<2>(cur) == get<0>(cur)->right)
        {
            tuple<TreeNode*, TreeNode*, TreeNode*, int>* dad = nullptr;
            if (get<3>(cur) != -1)
            {
                dad = &v[get<3>(cur)];
                if (get<0>(*dad)->left == get<0>(cur))
                {
                    get<1>(*dad) = get<0>(cur);
                }
                if (get<0>(*dad)->right == get<0>(cur))
                {
                    get<2>(*dad) = get<0>(cur);
                }
            }
            f.insert(get<0>(cur)->val);
            v.pop_back();
            continue;
        }
        int pos = v.size() - 1;
        auto node = get<0>(cur);
        if (node->left)
        {
            v.push_back(make_tuple(node->left, nullptr, nullptr, pos));
        }
        if (node->right)
        {
            v.push_back(make_tuple(node->right, nullptr, nullptr, pos));
        }
    }
    return f.size() == 1;
}
