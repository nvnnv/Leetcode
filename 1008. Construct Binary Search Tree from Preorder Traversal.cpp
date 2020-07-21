TreeNode* bstFromPreorder(vector<int>& preorder) {
    if (preorder.size() == 0) return nullptr;
    TreeNode* root = new TreeNode(preorder[0]);
    for (int i = 1; i < preorder.size(); ++i)
    {
        TreeNode* x = new TreeNode(preorder[i]);
        auto temp = root;
        while (true)
        {
            if (x->val < temp->val)
            {
                if (temp->left) temp = temp->left;
                else
                {
                    temp->left = x; break;
                }
            }
            if (x->val > temp->val)
            {
                if (temp->right) temp = temp->right;
                else {
                    temp->right = x; break;
                }
            }
        }
    }
    return root;
}









void createBST(TreeNode* root, TreeNode* x)
{
    if (x->val < root->val)
    {
        if (root->left)
        {
            createBST(root->left, x);
        }
        else root->left = x;
    }
    if (x->val > root->val)
    {
        if (root->right) createBST(root->right, x);
        else root->right = x;
    }
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
    if (preorder.size() == 0) return nullptr;
    TreeNode* root = new TreeNode(preorder[0]);
    for (int i = 1; i < preorder.size(); ++i)
    {
        TreeNode* x = new TreeNode(preorder[i]);
        createBST(root, x);
    }
    return root;
}
