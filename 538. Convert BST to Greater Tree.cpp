// loop
TreeNode* convertBST(TreeNode* root) {
    if (root == nullptr) return nullptr;
    vector<tuple<TreeNode*, int, int>> v;
    v.push_back(make_tuple(root, 0, -1));
    int sum = 0;
    while (!v.empty())
    {
        auto& cur = v.back();
        if ((get<0>(cur)->left == nullptr && get<0>(cur)->right == nullptr) || get<1>(cur) == 1)
        {
            if (get<2>(cur) != -1 && get<2>(cur) < v.size())
            {
                auto& dad = v[get<2>(cur)];
                get<1>(dad) = 1;
            }
            sum += get<0>(cur)->val;
            get<0>(cur)->val = sum;
            v.pop_back();
            continue;
        }
        int dadpos = v.size();
        auto node = get<0>(cur);
        auto cur1 = cur;
        v.pop_back();
        if (node->left) v.push_back(make_tuple(node->left, 0, dadpos));
        v.push_back(cur1);
        dadpos = v.size() - 1;
        if (node->right) v.push_back(make_tuple(node->right, 0, dadpos));
        else
        {
            sum += get<0>(cur1)->val;
            get<0>(cur1)->val = sum;
            if (get<2>(cur1) != -1 && get<2>(cur1) < v.size())
            {
                auto& dad = v[get<2>(cur1)];
                get<1>(dad) = 1;
            }
            v.pop_back();
        }
    }
    return root;
}


// recursion
void sumNodes(TreeNode* cur, int* sum)
{
    if (cur->left == nullptr && cur->right == nullptr)
    {
        cur->val += *sum;
        *sum = cur->val;
        return;
    }
    if(cur->right) sumNodes(cur->right, sum);

        cur->val += *sum;
        *sum = cur->val;
    if(cur->left) sumNodes(cur->left, sum);
}
TreeNode* convertBST(TreeNode* root) {
    if (root == nullptr) return nullptr;
    int xo = 0;
    sumNodes(root, &xo);
    return root;
}
