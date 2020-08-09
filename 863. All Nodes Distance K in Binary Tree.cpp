// first solution  924ms   using index
void xoxxo(TreeNode* cur, int base, int index, int& ni, int& m)
{
    if (cur == nullptr) return;
    if (cur->val == base) ni = index;
    m = max(index, m);
    xoxxo(cur->left, base, 2*index, ni,m);
    xoxxo(cur->right, base, 2*index+1, ni,m);
}
void findReIndex(int _index, unordered_set<int>& index_set, int& k, int step, unordered_set<int>& flag, int& ma)
{
    if (_index == 0 || _index > ma || flag.count(_index)) return;
    if (step == 0)
    {
        index_set.insert(_index);
        return;
    }
    flag.insert(_index);
    findReIndex(_index / 2, index_set, k, step - 1,flag,ma);
    findReIndex(2*_index, index_set, k, step - 1,flag,ma);
    findReIndex(2*_index+1, index_set, k, step - 1,flag,ma);
}
void findout(TreeNode* cur, int index, unordered_set<int>& index_set, vector<int>& ans)
{
    if (cur == nullptr) return;
    if (index_set.count(index))
    {
        ans.push_back(cur->val);
    }
    findout(cur->left, 2 * index, index_set, ans);
    findout(cur->right, 2 * index+1, index_set, ans);
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    if (root == nullptr) return {};

    int index = -1;
    int ma = 0;
    xoxxo(root, target->val, 1, index, ma);

    unordered_set<int> index_set;
    unordered_set<int> flag;
    findReIndex(index, index_set, K, K, flag, ma);
    vector<int> v;
    findout(root, 1, index_set, v);
    return v;
}


// second solution 12ms   convert tree to undirected map
void makeGraph(TreeNode* cur, unordered_map<int, vector<int>>& graph)
{
    if (cur->left == nullptr && cur->right == nullptr) return;

    if (cur->left)
    {
        graph[cur->val].push_back(cur->left->val);
        if (!graph.count(cur->left->val))
        {
            vector<int> v = { cur->val };
            graph[cur->left->val] = v;
        }
        makeGraph(cur->left, graph);
    }
    if (cur->right)
    {
        graph[cur->val].push_back(cur->right->val);
        if (!graph.count(cur->right->val))
        {
            vector<int> v = { cur->val };
            graph[cur->right->val] = v;
        }
        makeGraph(cur->right, graph);
    }
}
void findout(int point, int steps, unordered_map<int, vector<int>>& graph, unordered_set<int>& pass, int k, vector<int>& x)
{
    if (steps == k)
    {
        x.push_back(point);
        return;
    }
    for (auto& i : graph[point])
    {
        if (pass.count(i)) continue;
        pass.insert(i);
        findout(i, steps + 1, graph, pass, k, x);
        pass.erase(i);
    }
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    if (root == nullptr) return {};
    unordered_map<int, vector<int>> graph;
    vector<int> v;
    graph[root->val] = v;
    makeGraph(root, graph);
    unordered_set<int> pass;
    vector<int> x;
    pass.insert(target->val);
    findout(target->val, 0, graph, pass, K, x);
    return x;
}
