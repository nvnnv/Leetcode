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
