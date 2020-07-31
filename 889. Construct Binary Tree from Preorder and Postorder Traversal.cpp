TreeNode* reconstruct(vector<int>& pre, int& preP, vector<int>& post, int& postP, bool& turn)
{
    TreeNode* node = new TreeNode(pre[preP]);
    bool t = true;
    while (pre[preP] != post[postP])
    {
        bool f = t;
        preP++;
        auto son = reconstruct(pre, preP, post, postP, t);
        if (f) node->left = son;
        else node->right = son;
        if (post[postP] == node->val)
        {
            postP++;
            turn = !turn;
            return node;
        }
    }
    postP++;
    turn = !turn;
    return node;
}
TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    int x = 0, y = 0;
    bool f = true;
    return reconstruct(pre, x, post, y, f);
}
