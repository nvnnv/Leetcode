struct NodeEx {
    int dad = -1;
    int left = -1;
    int right = -1;
    TreeNode* cur = nullptr;
    int leftSubDeep = 0;
    int rightSubDeep = 0;
};
TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.size() < 1) return nullptr;
    TreeNode* root = nullptr;
    vector<NodeEx> v;
    for (auto i : nums)
    {
        TreeNode* cur = new TreeNode(i);
        if (root == nullptr)
        {
            root = cur;
            NodeEx ex;
            ex.cur = cur;
            v.push_back(ex);
        }
        else
        {
            NodeEx ex;
            ex.cur = cur;
            ex.dad = v.size() - 1;
            v.push_back(ex);
            auto* xo = &v[ex.dad];
            xo->cur->right = cur;
            xo->right = v.size() - 1;
            xo->rightSubDeep++;
            // update depth
            while (xo->dad != -1)
            {
                // must right > left   Left Rotation
                xo = &v[xo->dad];
                xo->rightSubDeep++;
                if (xo->rightSubDeep - xo->leftSubDeep > 1)
                {   
                    NodeEx* xoDad = xo;
                    if (xo->dad != -1)
                    {
                        xoDad = &v[xo->dad];
                    }
                    auto& son = v[xo->right];
                    // rotation
                    if (xoDad->cur != xo->cur)
                        xoDad->cur->right = son.cur;
                    else
                        root = son.cur;
                    xo->cur->right = son.cur->left;
                    son.cur->left = xo->cur;
                    // update index;
                    int temp = son.dad;
                    son.dad = xo->dad;
                    xoDad->right = xo->right;
                    xo->dad = xo->right;
                    xo->right = son.left;
                    son.left = temp;
                    // update depth
                    xo->rightSubDeep = son.leftSubDeep;
                    son.leftSubDeep = max(xo->rightSubDeep, xo->leftSubDeep)+1;
                    break;
                }
            }
        }
    }
    return root;
}
