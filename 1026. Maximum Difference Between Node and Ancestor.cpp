void findMaxOnAnce(TreeNode* cur, int& ans, int ma, int mi)
{
    if (cur == nullptr) return;
    int curMax = max(cur->val, ma);
    int curMin = min(cur->val, mi);
    if (abs(curMax - cur->val) > ans) ans = abs(curMax - cur->val);
    if (abs(cur->val - curMin) > ans) ans = abs(cur->val - curMin);
    findMaxOnAnce(cur->left, ans, curMax, curMin);
    findMaxOnAnce(cur->right, ans, curMax, curMin);
}
int maxAncestorDiff(TreeNode* root) {
    int ans = 0;
    findMaxOnAnce(root, ans, 0, 999999);
    return ans;
}
