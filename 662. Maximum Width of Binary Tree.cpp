int widthOfBinaryTree(TreeNode* root) {
    vector<pair<TreeNode*, int>> nodes;
    nodes.push_back(make_pair(root, 1));
    int m = 1;
    while (!nodes.empty())
    {
        vector<pair<TreeNode*, int>> tnodes;
        int i = 0;
        for (auto& p : nodes)
        {
            if (p.first->left)
            {
                tnodes.push_back(make_pair(p.first->left, p.second * 2 - 1));
            }
            if (p.first->right)
            {
                tnodes.push_back(make_pair(p.first->right, p.second * 2));
            }
        }
        if (tnodes.size() > 0)
        {
            int f = tnodes[0].second;
            if (f > 1)
            {
                for (auto& p : tnodes)
                {
                    p.second = p.second - f + 1;
                }
            }
            m = max(m, tnodes.back().second - tnodes[0].second + 1);
        }
        nodes = tnodes;
    }
    return m;
}
