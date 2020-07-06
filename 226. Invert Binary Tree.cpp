// recursion
void xxoo(TreeNode* cur)
{
    if (cur->left == NULL && cur->right == NULL)
    {
        return;
    }
    auto left = cur->left;
    cur->left = cur->right;
    cur->right = left;
    if (cur->left) xxoo(cur->left);
    if (cur->right) xxoo(cur->right);
}
TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return nullptr;
    
    xxoo(root);
    return root;
}

// loop

TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return nullptr;
    vector<tuple<TreeNode*, TreeNode*, TreeNode*, int>> v;
    v.push_back(make_tuple(root, nullptr, nullptr, -1));
    while (!v.empty())
    {
        auto& cur = v.back();
        if (get<0>(cur)->right == get<2>(cur) && get<0>(cur)->left == get<1>(cur))
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
            v.pop_back();
            continue;
        }
        int pos = v.size() - 1;
        auto node = get<0>(cur);
        auto left = node->left;
        node->left = node->right;
        node->right = left;
        if (node->left) v.push_back(make_tuple(node->left, nullptr, nullptr, pos));
        if (node->right) v.push_back(make_tuple(node->right, nullptr, nullptr, pos));
    }
    return root;
}
