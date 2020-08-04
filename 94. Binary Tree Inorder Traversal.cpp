vector<int> inorderTraversal(TreeNode* root) {
    if (root == nullptr) return {};
    vector<int> x;
    vector<tuple<TreeNode*, int, int>> v;
    v.push_back(make_tuple(root, 0, -1));
    while (!v.empty())
    {
        auto& cur = v.back();
        if ((get<0>(cur)->left == nullptr && get<0>(cur)->right == nullptr) || get<1>(cur) == 1)
        {
            if (get<2>(cur) != -1)
            {
                auto& dad = v[get<2>(cur)];
                get<1>(dad) = 1;
            }
            x.push_back(get<0>(cur)->val);
            v.pop_back();
            continue;
        }
        int pos = v.size();
        auto cur1 = cur;
        auto data = get<0>(cur);
        v.pop_back();
        if (data->right) v.push_back(make_tuple(data->right, 0, v.size()+1));
        get<1>(cur1) = 1;
        v.push_back(cur1);
        if (data->left) v.push_back(make_tuple(data->left, 0, v.size()-1));
    }
    return x;
}
