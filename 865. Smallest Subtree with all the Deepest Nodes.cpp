int findLCA(int ma, int mi)
{
    int ma1 = ma;
    int mi1 = mi;
    while (ma1 > mi1)
    {
        ma1 = ma1 / 2;
    }
    if (ma1 == mi1) return ma1;
    while (ma != mi)
    {
        if (ma > mi)
        {
            ma = ma / 2;
        }
        if (ma < mi)
        {
            mi = mi / 2;
        }
    }
    return ma;
}
void xxoo(TreeNode* cur, int level, int index, int& ans_index, int& deepest)
{
    if (cur == nullptr) return;
    if (deepest == level)
    {
        ans_index = findLCA(ans_index, index);
    }
    if (deepest < level)
    {
        deepest = level;
        ans_index = index;
    }
    xxoo(cur->left, level + 1, 2*index, ans_index, deepest);
    xxoo(cur->right, level + 1, 2*index+1, ans_index, deepest);
}
void aim(TreeNode* cur, int index, int& ans_intdex, TreeNode** ans)
{
    if(cur == nullptr) return;
    if (index == ans_intdex)
    {
        *ans = cur;
        return;
    }
    aim(cur->left, 2 * index, ans_intdex, ans);
    aim(cur->right, 2 * index+1, ans_intdex, ans);
}
TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    int index = 0;
    int deepest = 0;
    xxoo(root, 1, 1, index, deepest);
    TreeNode* ans;
    aim(root, 1, index, &ans);
    return ans;
}
