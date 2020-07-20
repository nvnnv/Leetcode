void findGrandPar(TreeNode* cur, TreeNode* curP, TreeNode* curPP, int& sum)
{
    if (curPP)
    {
        if (curPP->val % 2 == 0) sum += cur->val;
    }
    if (cur->left == nullptr && cur->right == nullptr)
    {
        return;
    }
    if (cur->left) findGrandPar(cur->left, cur, curP, sum);
    if (cur->right) findGrandPar(cur->right, cur, curP, sum);
}
int sumEvenGrandparent(TreeNode* root) {
    if (root == nullptr) return 0;
    int sum = 0;
    findGrandPar(root, nullptr, nullptr, sum);
    return sum;
}

 int sumEvenGrandparent(TreeNode* root) {
    if (root == nullptr) return 0;
    int sum = 0;
    vector<tuple<TreeNode*, TreeNode*, TreeNode*, int, int>> v;
    v.push_back(make_tuple(root, nullptr, nullptr, 0, -1));
    while (!v.empty())
    {
        auto& cur = v.back();
        if ((get<0>(cur)->left == nullptr && get<0>(cur)->right == nullptr) || get<3>(cur) == 1)
        {
            if (get<4>(cur) != -1)
            {
                auto& par = v[get<4>(cur)];
                get<3>(par) = 1;
            }
            if (get<2>(cur) != nullptr)
            {
                if(get<2>(cur)->val %2 ==0) sum += get<0>(cur)->val;
            }
            v.pop_back();
            continue;
        }
        int length = v.size() - 1;
        auto node = get<0>(cur);
        auto PPn = get<1>(cur);
        if (node->left) v.push_back(make_tuple(node->left, node, PPn, 0, length));
        if (node->right) v.push_back(make_tuple(node->right, node, PPn, 0, length));
    }
    return sum;
}
 
