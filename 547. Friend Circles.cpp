# union find
int merge(vector<int>& uf, int x, int y)
{
    if (uf[x] == x && uf[y] == y)
    {
        int t = min(x, y);
        uf[x] = t; uf[y] = t;
        return t;
    }
    while (uf[x] != uf[y])
    {
        int f = merge(uf, uf[x], uf[y]);
        uf[x] = f;
        uf[y] = f;
    }
    return uf[x];
}
int find(vector<int>& uf, int x)
{
    while (uf[x] != x)
    {
        x = uf[x];
    }
    return x;
}
int findCircleNum(vector<vector<int>>& M) {
    int num = 0;
    vector<int> uf(M.size(), -1);
    for (int i = 0; i < M.size(); ++i)
    {
        uf[i] = i;
    }
    for (int i = 0; i < M.size(); ++i)
    {
        for (int j = 0; j < M[i].size(); ++j)
        {
            if (M[i][j] == 1 && i!=j)
            {
                merge(uf, i, j);
            }
        }
    }
    unordered_set<int> s;
    for (int i = 0; i < uf.size(); ++i)
    {
        s.insert(find(uf, i));
    }
    return s.size();
}
# brute force dfs
void nimei(unordered_map<int, vector<int>>& gra, int i, vector<int>& v)
{
    if (v[i]) return;
    v[i] = 1;
    for (int j = 0; j < gra[i].size(); ++j)
    {
        nimei(gra, gra[i][j], v);
    }
    return;
}
int findCircleNum(vector<vector<int>>& M) {
    unordered_map<int, vector<int>> gra;
    for (int i = 0; i < M.size(); ++i)
    {
        for (int j = 0; j < M[i].size(); ++j)
        {
            if (M[i][j] == 1)
            {
                if (!gra.count(i))
                {
                    vector<int> v;
                    gra[i] = v;
                }
                if (!gra.count(j))
                {
                    vector<int> v;
                    gra[j] = v;
                }
                gra[i].push_back(j);
                gra[j].push_back(i);
            }
        }
    }
    vector<int> vis(M.size(), 0);
    int num = 0;
    for (int i = 0; i < M.size(); ++i)
    {
        if (vis[i]) continue;
        nimei(gra, i, vis);
        ++num;
    }
    return num;
}
