void countGoodNodes(TreeNode* cur, int& x, int nodeMax)
{
    if (cur == nullptr) return;
    if (cur->val >= nodeMax)
    {
        ++x;
    }
    nodeMax = max(nodeMax, cur->val);
    countGoodNodes(cur->left, x, nodeMax);
    countGoodNodes(cur->right, x, nodeMax);
}
int goodNodes(TreeNode* root) {
    if (root == nullptr) return 0;
    int sum = 0;
    countGoodNodes(root, sum, root->val);
    return sum;
}


int goodNodes(TreeNode* root) {
    if (root == nullptr) return 0;
    int sum = 0;
    int pathMax = 0;
    vector<tuple<TreeNode*, int,int, int>> v;
    v.push_back(make_tuple(root, 0,-9999999, -1));
    while (!v.empty())
    {
        auto& cur = v.back();
        if ((get<0>(cur)->left == nullptr && get<0>(cur)->right == nullptr) || get<1>(cur) == 1)
        {
            if (get<3>(cur) != -1)
            {
                auto& dad = v[get<3>(cur)];
                get<1>(dad) = 1;
            }
            if (get<0>(cur)->left == nullptr && get<0>(cur)->right == nullptr)
            {
                if (get<0>(cur)->val >= get<2>(cur)) ++sum;
            }
            v.pop_back();
            continue;
        }
        int max = get<2>(cur);
        if (get<0>(cur)->val >= max)
        {
            ++sum;
            max = get<0>(cur)->val;
        }
        int dadpos = v.size() - 1;
        auto node = get<0>(cur);
        if (node->left) v.push_back(make_tuple(node->left, 0, max, dadpos));
        if (node->right) v.push_back(make_tuple(node->right, 0,max, dadpos));
    }
    return sum;
}
