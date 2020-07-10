vector<double> averageOfLevels(TreeNode* root) {
     vector<double> ans;
    if(root == nullptr) return ans;
    map<int, vector<int>> levels;
    vector<tuple<TreeNode*, TreeNode*, TreeNode*, int, int>> v;
    v.push_back(make_tuple(root, nullptr, nullptr, 1, -1));
    while (!v.empty())
    {
        auto& cur = v.back();
        if (get<0>(cur)->left == get<1>(cur) && get<0>(cur)->right == get<2>(cur))
        {
            if (get<4>(cur) != -1)
            {
                auto& dad = v[get<4>(cur)];
                if (get<0>(dad)->left == get<0>(cur))
                {
                    get<1>(dad) = get<0>(cur);
                }
                if (get<0>(dad)->right == get<0>(cur))
                {
                    get<2>(dad) = get<0>(cur);
                }
            }
            v.pop_back();
            continue;
        }
        int dadPos = v.size() - 1;
        int level = get<3>(cur)+1;
        auto node = get<0>(cur);
        if (!levels.count(level))
        {
            vector<int> x;
            levels[level] = x;
        }
        if (node->left)
        {
            v.push_back(make_tuple(node->left, nullptr, nullptr, level, dadPos));
            levels[level].push_back(node->left->val);
        }
        if (node->right)
        {
            v.push_back(make_tuple(node->right, nullptr, nullptr, level, dadPos));
            levels[level].push_back(node->right->val);
        }
    }
   
        // add root
    ans.push_back(root->val);
    for (auto p : levels)
    {
        double mean = 0.0;
        for (auto i : p.second)
        {
            mean += i;
        }
        ans.push_back(mean / p.second.size());
    }
    return ans;
}
