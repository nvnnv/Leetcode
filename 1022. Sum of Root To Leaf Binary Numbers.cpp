int sumRootToLeaf(TreeNode* root) {
    if (root == nullptr) return 0;
    vector<int> bits;
    int ans = 0;
    vector<tuple<TreeNode*, TreeNode*, TreeNode*, int>> v; // cur, left,right,dad
    v.push_back(make_tuple(root, nullptr, nullptr, -1));
    while (!v.empty())
    {
        auto& cur = v.back();
        if (get<0>(cur)->left == nullptr && get<0>(cur)->right == nullptr)
        { // leaf node added here, non-leaf below
            bits.push_back(get<0>(cur)->val);
        }
        if (get<1>(cur) == get<0>(cur)->left && get<2>(cur) == get<0>(cur)->right)
        {
            tuple<TreeNode*, TreeNode*, TreeNode*, int>* dad = NULL;
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
            if (get<0>(cur)->left == nullptr && get<0>(cur)->right == nullptr)
            {
                // only leaf needed
                int temp = 0;
                for (auto i = bits.begin(); i != bits.end(); ++i)
                {
                    temp = (temp | *i) << 1;
                }
                ans += temp >> 1;
            }
            bits.pop_back();
            continue;
        }
        bits.push_back(get<0>(cur)->val);
        int dad_pos = v.size() - 1;
        auto node = get<0>(cur);
        if(node->right) v.push_back(make_tuple(node->right, nullptr, nullptr, dad_pos));
        if(node->left) v.push_back(make_tuple(node->left, nullptr, nullptr, dad_pos));
    }
    return ans;
}
