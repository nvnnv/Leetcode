
TreeNode* reconstructTree(vector<int>& in, int i_left, int i_right, vector<int>& post, int& p)
{
    TreeNode* x = nullptr;
    for (int i = i_left; i <= i_right; ++i)
    {
        if (in[i] == post[p])
        {
            x = new TreeNode(in[i]);
            if (i + 1 <= i_right)
            {
                --p;
                x->right = reconstructTree(in, i + 1, i_right, post, p);
            }
            if (i_left <= i - 1)
            {
                --p;
                x->left = reconstructTree(in, i_left, i - 1, post, p);
            }
            break;
        }
    }
    return x;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int l = postorder.size() - 1;
    auto x = reconstructTree(inorder, 0, inorder.size() - 1, postorder, l);
    return x;
}
