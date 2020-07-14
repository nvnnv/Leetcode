void mirror(TreeNode* left, TreeNode* right, bool& f)
{
    if (left->val == right->val)
    {
        if (left->left == NULL && left->right == NULL && right->left == NULL && right->right == NULL)
        {
            return;
        }
        if (left->left && right->right)
        {
            mirror(left->left, right->right,f);
        }
        else
        {
            if ((left->left == NULL && right->right != NULL) || (left->left != NULL && right->right==NULL))
            {
                f = 0;
            }
        }
        if (left->right && right->left)
        {
            mirror(left->right, right->left, f);
        }
        else
        {
            if ((left->right != NULL && right->left==NULL )||( left->right==NULL && right->left != NULL))
            {
                f = 0;
            }
        }
        return;
    }
    f = false;
}
bool isSymmetric(TreeNode* root) {
    if (root == nullptr) return true;
    bool f = 1;
    if (root->left && root->right)
        mirror(root->left, root->right, f);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return f;
}


// loop
bool isSymmetric(TreeNode* root) {
    if (root == nullptr) return true;
    bool f = 1;
    if (root->left && root->right)
    {
        vector<tuple<TreeNode*, TreeNode*, int, int>> v;
        v.push_back(make_tuple(root->left, root->right, 0, -1));
        while (!v.empty())
        {
            auto& cur = v.back();
            if ((get<0>(cur)->left == nullptr && get<0>(cur)->right == nullptr && get<1>(cur)->left == nullptr && get<1>(cur)->right == nullptr && get<0>(cur)->val == get<1>(cur)->val) || (get<2>(cur) == 1))
            {
                if (get<3>(cur) != -1)
                {
                    auto& dad = v[get<3>(cur)];
                    get<2>(dad) = 1;
                }
                v.pop_back();
                continue;
            }
            int dadpos = v.size() - 1;
            auto node1 = get<0>(cur);
            auto node2 = get<1>(cur);
            if (node1->left && node2->right && node1->val == node2->val)
            {
                v.push_back(make_tuple(node1->left, node2->right, 0, dadpos));
            }
            else
            {
                if ((node1->left != nullptr && node2->right == nullptr) || (node1->left == nullptr && node2->right != nullptr) || node1->val != node2->val)
                {
                    f = 0;
                    break;
                }
            }
            if (node1->right && node2->left && node1->val == node2->val)
            {
                v.push_back(make_tuple(node1->right, node2->left, 0, dadpos));
            }
            else
            {
                if ((node1->right != nullptr && node2->left == nullptr) || (node1->right == nullptr && node2->left != nullptr) || node1->val != node2->val)
                {
                    f = 0;
                    break;
                }
            }
        }
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return f;
}
