TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1 == NULL) return t2;
    if (t2 == NULL) return t1;
    stack<tuple<TreeNode*, TreeNode*, bool, TreeNode*, TreeNode*>> s;
    s.push(make_tuple(t1, t2, true, nullptr, nullptr));
    auto* root = t1;
    while (!s.empty())
    {
        auto& cur = s.top();
        if (!get<2>(cur) || (get<0>(cur)==NULL && get<1>(cur) == NULL))
        {
            s.pop();
            continue;
        }
        if (get<0>(cur) != NULL && get<1>(cur) != NULL)
        { 
            get<0>(cur)->val += get<1>(cur)->val;
            get<2>(cur) = false;
            s.push(make_tuple(get<0>(cur)->left, get<1>(cur)->left, true, get<0>(cur), get<1>(cur)));
            s.push(make_tuple(get<0>(cur)->right, get<1>(cur)->right, true, get<0>(cur), get<1>(cur)));
        }
        if (get<0>(cur) != NULL && get<1>(cur) == NULL)
        {
            get<2>(cur) = false;
            s.pop();
        }
        if (get<0>(cur) == NULL && get<1>(cur) != NULL)
        {
            get<2>(cur) = false;
            if (get<4>(cur)->left == get<1>(cur)) get<3>(cur)->left = get<1>(cur);
            if (get<4>(cur)->right == get<1>(cur)) get<3>(cur)->right = get<1>(cur);
            s.pop();
        }
    }
    return root;;
}
