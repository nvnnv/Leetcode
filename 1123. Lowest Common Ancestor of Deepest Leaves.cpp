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
void findLCAD(TreeNode* cur, int num, int level, int& deepest, vector<pair<TreeNode*, int>>& deepestL)
{
    if (cur->left == nullptr && cur->right == nullptr)
    {
        if (level == deepest) deepestL.push_back(make_pair(cur, num));
        if (level > deepest)
        {
            deepest = level;
            deepestL.clear();
            deepestL.push_back(make_pair(cur, num));
        }
        return;
    }
    if (cur->left) findLCAD(cur->left, 2 * num, level + 1, deepest, deepestL);
    if (cur->right) findLCAD(cur->right, 2 * num + 1, level + 1, deepest, deepestL);
}
void index(TreeNode* cur, int num, int ind, TreeNode** x)
{
    if (num == ind)
    {
        *x = cur;
        return;
    }
    if (cur == nullptr) return;
    if (*x == nullptr)
    {
        index(cur->left, 2 * num, ind, x);
        index(cur->right, 2 * num + 1, ind, x);
    }
}
TreeNode* lcaDeepestLeaves(TreeNode* root) {
    if (root == nullptr) return root;
    vector<pair<TreeNode*, int>> lea;
    int deep = 0;
    findLCAD(root, 1, 0, deep, lea);
    if (lea.size() == 1) return lea[0].first;
    int ind = findLCA(lea[0].second, lea[lea.size() - 1].second);
    TreeNode* x = nullptr;
    index(root, 1, ind, &x);
    return x;
}

# new way to solve it
class Solution:
    def lcaDeepestLeaves(self, root: TreeNode) -> TreeNode:
        if root is None:
            return None
        
        ansNode = []
        deepest = [0]
        def dfs(node, deep):
            if node is None:
                return deep
            
            left = dfs(node.left, deep+1)
            right = dfs(node.right, deep+1)
            
            if left == right and left >= deepest[0]:
                ansNode.append(node)
                deepest[0] = left
                
            return max(left, right)
        dfs(root, 0)
        return ansNode[-1]
