void levelOrder1(TreeNode* cur, int level, vector<vector<TreeNode*>>& order)
{
    if (cur == nullptr) return;
    if (level >= order.size())
    {
        vector<TreeNode*> v;
        order.push_back(v);
    }
    order[level].push_back(cur);
    levelOrder1(cur->left, level + 1, order);
    levelOrder1(cur->right, level + 1, order);
}
bool isCompleteTree(TreeNode* root) {
    if (root->left == NULL && root->right == NULL) return true;
    vector<vector<TreeNode*>> order;
    levelOrder1(root, 0, order);
    int i = 1;
    int len = order.size();
    for (int j = 0; j < len - 1; ++j)
    {
        if (order[j].size() != i) return false;
        i *= 2;
    }
    if (order[len - 1].size() == i) return true;
    else
    {
        if (len < 3)
        {
            // only 2
            auto& data = order[0][0];
            auto& son = order[1][0];
            if (data->left == son) return true;
            else return false;
        }
        else
        {
            auto& last_2 = order[len - 2];
            auto& last_1 = order[len - 1];
            int _len = order[len - 1].size();
            int j = 1;
            int k = 0;
            for (j; j < _len; j += 2)
            {
                if (last_1[j - 1] != last_2[k]->left || last_2[k]->right != last_1[j]) return false;
                ++k;
            }
            if (_len % 2)
            {
                --j;
                if (last_1[j] != last_2[k]->left) return false;
            }
            return true;
        }
    }
}
