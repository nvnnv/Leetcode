
int find(int x, unordered_map<int, int>& m, int& is)
{
    if (!m.count(x))
    {
        m[x] = x; ++is;
    }
    while (x != m[x])
    {
        x = m[x];
    }
    return x;
}
void unionfind(int x, int y, unordered_map<int, int>& m, int& is)
{
    int fx = find(x, m, is);
    int fy = find(y, m, is);
    if (fx > fy) { m[fx] = fy; --is; }
    if (fx < fy) { m[fy] = fx; --is; }
}
int removeStones(vector<vector<int>>& stones) {
    unordered_map<int, int> m;
    int is = 0;
    for (auto& v : stones)
    {
        unionfind(v[0], v[1] + 10000, m, is);
    }
    return stones.size() - is;
}
