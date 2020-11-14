int find1(int x, vector<int>& us)
{
    if (us[x] == -1) {
        us[x] = x;
    }
    while (x != us[x])
    {
        x = us[x];
    }
    return x;
}
void unionF(int x, int y, vector<int>& us)
{
   x = find1(x, us);
    y = find1(y, us);
    if (x != y) { us[y] = x; }
}
int makeConnected(int n, vector<vector<int>>& connections) {
    vector<int> f(n, -1);
    for (auto& v : connections)
    {
        unionF(v[0], v[1], f);
    }
    unordered_map<int, vector<int>> xx;
    for (int i = 0; i < n; ++i)
    {
        int x = find1(i, f);
        if (!xx.count(x))
        {
            vector<int> v;
            xx[x] = v;
        }
        xx[x].push_back(i);
    }
    int min_edge = 0;
    for (auto p : xx)
    {
        min_edge += p.second.size() - 1;
    }
    int left = connections.size() - min_edge;
    if (left < xx.size() - 1) return -1;
    return xx.size() - 1;
}
