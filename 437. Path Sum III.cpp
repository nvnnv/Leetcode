void xxo(TreeNode* cur, int& s, int& sum, vector<int>& pathS, int level)
{
    if (!pathS.empty())
    {
        int b = pathS.size() - level;
        int size = pathS.size();
        int temp = 0;
        for (b; b < size; ++b)
        {
            temp = pathS[b] + cur->val;
            pathS.push_back(temp);
            if (temp == sum) ++s;
        }
    }
    pathS.push_back(cur->val);
    if (cur->val == sum) ++s;
    if (cur->right == nullptr && cur->left == nullptr)
    {
        int x = level + 1;
        while (x--)
        {
            pathS.pop_back();
        }
        return;
    }
    if (cur->left)
    {
        xxo(cur->left, s, sum, pathS, level+1);
    }
    if (cur->right)
    {
        xxo(cur->right, s, sum, pathS, level +1);
    }
    int x = level + 1;
    while (x--)
    {
        pathS.pop_back();
    }
}
int pathSum(TreeNode* root, int sum) {
    if (root == nullptr) return 0;
    int s = 0;
    vector<int> xo;
    xxo(root, s, sum, xo, 0);
    return s;
}
