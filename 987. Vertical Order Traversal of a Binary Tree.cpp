struct cmp5
{
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2)
    {
        if(p1.second == p2.second) return p1.first > p2.first;
        return p1.second > p2.second;
    }
};
void updateVindex(TreeNode* cur, int c, int level, unordered_map<int, priority_queue<pair<int,int>, vector<pair<int, int>>, cmp5>>& vLevel, int& b, int& e)
{
    if (cur == nullptr) return;
    if (vLevel.count(c) == 0)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp5> v;
        vLevel[c] = v;
    }
    vLevel[c].push(make_pair(cur->val, level));
    cur->val = c;
    b = min(c, b);
    e = max(c, e);
    updateVindex(cur->left, c - 1, level+1, vLevel, b, e);
    updateVindex(cur->right, c + 1, level+1, vLevel, b, e);
}
vector<vector<int>> verticalTraversal(TreeNode* root) {
    unordered_map<int, priority_queue<pair<int, int>, vector<pair<int, int>>, cmp5>> vLevel;
    int begin = 0;
    int end = 0;
    updateVindex(root, 1, 1, vLevel, begin, end);
    vector<vector<int>> res;
    for (int i = begin; i <= end; ++i)
    {
        if (vLevel.count(i))
        {
            vector<int> x;
            while(!vLevel[i].empty())
            {
                x.push_back(vLevel[i].top().first);
                vLevel[i].pop();
            }
            res.push_back(x);
        }
    }
    return res;
}
