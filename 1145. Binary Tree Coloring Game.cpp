void makeGraph1(TreeNode* cur, unordered_map<int, vector<int>>& graph)
{
    if (cur == nullptr) return;
    if (cur->left)
    {
        if (!graph.count(cur->left->val))
        {
            vector<int> v;
            graph[cur->left->val] = v;
        }
        graph[cur->left->val].push_back(cur->val);
        graph[cur->val].push_back(cur->left->val);
        makeGraph1(cur->left, graph);
    }
    if (cur->right)
    {
        if (!graph.count(cur->right->val))
        {
            vector<int> v;
            graph[cur->right->val] = v;
        }
        graph[cur->right->val].push_back(cur->val);
        graph[cur->val].push_back(cur->right->val);
        makeGraph1(cur->right, graph);
    }
}
void countPoint(int point, unordered_map<int, vector<int>>& graph, unordered_set<int>& s, int& x)
{
    s.insert(point);
    for (auto i : graph[point])
    {
        if (s.count(i)) continue;
        ++x;
        countPoint(i, graph, s, x);
    }
}
bool btreeGameWinningMove(TreeNode* root, int n, int x) {
    unordered_map<int, vector<int>> graph;
    makeGraph1(root, graph);
    vector<int> ps;
    for (auto& v : graph[x])
    {
        unordered_set<int> s;
        s.insert(x);
        int part = 1;
        countPoint(v, graph, s, part);
        ps.push_back(part);
    }
    sort(ps.begin(), ps.end());
    int sum = 0;
    for (auto i : ps) sum += i;
    return ps.back() > sum - ps.back();
}
