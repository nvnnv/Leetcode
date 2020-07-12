void print1(TreeNode* cur, map<int,int>& x)
{
    if (cur->left == nullptr && cur->right == nullptr)
    {
        x[cur->val] = 1;
        return;
    }
      if(cur->left)  print1(cur->left, x);
        x[cur->val] = 1;
       if(cur->right) print1(cur->right, x);

}
int getMinimumDifference(TreeNode* root) {
    if (root == nullptr) return 0;
    map<int, int> x;
    print1(root, x);
    int mi = 9999999;
    auto it = x.begin();
    auto xt = x.begin();
    xt++;
    for (xt; xt != x.end(); ++xt)
    {
        mi = min(mi, xt->first - it->first);
        it++;
    }
    return mi;
}
