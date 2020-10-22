void from0(unordered_map<int, vector<int>>& m, int x, unordered_set<int>& fp)
{
    if (fp.count(x)) return;
    fp.insert(x);
    for (int i = 0; i < m[x].size(); ++i)
    {
        from0(m, m[x][i], fp);
    }
}
bool canVisitAllRooms(vector<vector<int>>& rooms) {
    if (rooms.size() <= 0) return false;
    unordered_map<int, vector<int>> m;
    unordered_set<int> fp;
    for (int i = 0; i < rooms.size(); ++i)
    {
        if (!m.count(i))
        {
            vector<int> aa;
            m[i] = aa;
        }
        for (int j = 0; j < rooms[i].size(); ++j)
        {
            m[i].push_back(rooms[i][j]);
        }
    }
    from0(m, 0, fp);
    return fp.size() == rooms.size();
}
