TreeNode* trimBST(TreeNode* root, int L, int R) {
    if (root == nullptr) return nullptr;
    
    vector<tuple<TreeNode*, TreeNode*, TreeNode*, int>> v;
    v.push_back(make_tuple(root, nullptr, nullptr, -1));
    while (!v.empty())
    {
        auto& cur = v.back();
        if (get<0>(cur)->left == get<1>(cur) && get<0>(cur)->right == get<2>(cur))
        {
            if (get<3>(cur) != -1)
            {
                auto& dad = v[get<3>(cur)];
                if (get<0>(cur)->val < L || get<0>(cur)->val > R)
                {
                    if (get<0>(dad)->left == get<0>(cur))
                    {
                        
                        if (get<0>(cur)->val < L)
                        {
                            get<1>(dad) = get<0>(cur)->right;
                            get<0>(dad)->left = get<0>(cur)->right;
                        }
                        else
                        {
                            get<1>(dad) = get<0>(cur)->left;
                            get<0>(dad)->left = get<0>(cur)->left;
                        }

                    }
                    if (get<0>(dad)->right == get<0>(cur))
                    {
                        
                        if (get<0>(cur)->val < L)
                        {
                            get<2>(dad) = get<0>(cur)->right;
                            get<0>(dad)->right = get<0>(cur)->right;
                        }
                        else
                        {
                            get<2>(dad) = get<0>(cur)->left;
                            get<0>(dad)->right = get<0>(cur)->left;
                        }
                    }
                    //delete get<0>(cur);
                }
                else
                {
                    if (get<0>(dad)->left == get<0>(cur))
                    {
                        get<1>(dad) = get<0>(cur);
                    }
                    if (get<0>(dad)->right == get<0>(cur))
                    {
                        get<2>(dad) = get<0>(cur);
                    }
                }
            }
            else
            {
                if (get<0>(cur)->val < L)
                    root = root->right;
                if(get<0>(cur)->val > R)
                    root = root->left;
                // delete get<0>(cur);
            }
            v.pop_back();
            continue;
        }
        int dadPos = v.size() - 1;
        auto node = get<0>(cur);
        if (node->left) v.push_back(make_tuple(node->left, nullptr, nullptr, dadPos));
        if (node->right) v.push_back(make_tuple(node->right, nullptr, nullptr, dadPos));
    }
    return root;
}


void deleteTree(TreeNode* root)
{
    if (root == nullptr)
    {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
void trimBST_(TreeNode* dad, TreeNode* cur, int L, int R, TreeNode** root)
{
    if (cur->val < L)
    {
        if (dad == nullptr)
        {
            *root = cur->right;
        }
        else
        {
            if (dad->left == cur) dad->left = cur->right;
            else dad->right = cur->right;
        }
        if (cur->right) trimBST_(dad, cur->right, L, R, root);
        //deleteTree(cur->left);
        //delete cur;
        return;
    }
    if (cur->val > R)
    {
        if (dad == nullptr)
        {
            *root = cur->left;
        }
        else
        {
            if (dad->left == cur) dad->left = cur->left;
            else dad->right = cur->left;
        }
        if (cur->left) trimBST_(dad, cur->left, L, R, root);
       // deleteTree(cur->right);
        // delete cur;
        return;
    }
    if (cur->left) trimBST_(cur, cur->left, L, R, root);
    if (cur->right) trimBST_(cur, cur->right, L, R, root);
}

TreeNode* trimBST(TreeNode* root, int L, int R) {
    if (root == nullptr) return nullptr;
    
    trimBST_(nullptr, root, L, R, &root);
    return root;
}
