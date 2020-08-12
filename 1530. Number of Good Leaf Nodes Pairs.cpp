// 540ms
void changeValue(TreeNode* cur, int& index)
{
    if (cur == nullptr) return;
    cur->val = index++;
    changeValue(cur->left, index);
    changeValue(cur->right, index);
}
void drawGraph(TreeNode* cur,  unordered_set<long long>& leaves, unordered_map<long long, vector<long long>>& graph)
{
    if (cur->left == NULL && cur->right == NULL)
    {
        leaves.insert(cur->val);
        return;
    }
    if (cur->left)
    {
        graph[cur->val].push_back(cur->left->val);
        if (!graph.count(cur->left->val))
        {
            vector<long long> v = { cur->val };
            graph[cur->left->val] = v;
        }
        else
        {
            graph[cur->left->val].push_back(cur->val);
        }
        drawGraph(cur->left, leaves, graph);
    }
    if (cur->right)
    {
        graph[cur->val].push_back(cur->right->val);
        if (!graph.count(cur->right->val))
        {
            vector<long long> v = { cur->val };
            graph[cur->right->val] = v;
        }
        else
        {
            graph[cur->right->val].push_back(cur->val);
        }
        drawGraph(cur->right, leaves, graph);
    }
}
void search(long long point, unordered_map<long long, vector<long long>>& graph, unordered_set<long long>& pass, int dist, int& max_dist, int& num, unordered_set<long long>& pass_leaf)
{
    if (dist > max_dist)
    {
        pass.erase(point);
        return;
    }
    if (pass_leaf.count(point) && dist != 0)
    {
        ++num;
        pass.erase(point);
        return;
    }
    pass.insert(point);
    for (auto i : graph[point])
    {
        if (pass.count(i)) continue;
        search(i, graph, pass, dist + 1, max_dist, num, pass_leaf);
    }
    pass.erase(point);
}
int countPairs(TreeNode* root, int distance) {
    unordered_map<long long, vector<long long>> graph;
    unordered_set<long long> leaves;
    int i = 0;
    changeValue(root, i);
    drawGraph(root, leaves, graph);
    int num = 0;
    auto iter = leaves.begin();
    while(iter != leaves.end())
    {
        unordered_set<long long> pass;
        int x = num;
        search(*iter, graph, pass, 0, distance, num, leaves);
        //if(num > x) iter = le
        iter = leaves.erase(iter);
    }
    return num;
}
