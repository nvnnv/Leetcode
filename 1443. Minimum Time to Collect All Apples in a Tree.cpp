bool moveApple(int point, int prev, unordered_map<int, vector<int>>& roads, vector<bool>& hasApple, int& steps)
{
    if (!roads.count(point) && hasApple[point])
    {
        return true;
    }
    bool f = false;
    for (auto i : roads[point])
    {
        if (i == prev) continue;
        bool ff = moveApple(i, point, roads, hasApple, steps);
        if (ff)
        {
            steps += 2;
        }
        f = f || ff;
    }
    return f || hasApple[point];
}
int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    unordered_map<int, vector<int>> roads;
    for (auto& v : edges)
    {
        if (roads.count(v[0]))
        {
            roads[v[0]].push_back(v[1]);
        }
        else
        {
            vector<int> vv = { v[1] };
            roads[v[0]] = vv;
        }
        if (roads.count(v[1]))
        {
            roads[v[1]].push_back(v[0]);
        }
        else
        {
            vector<int> vv = { v[0] };
            roads[v[1]] = vv;
        }
    }
    int sec = 0;
    moveApple(0, -1, roads, hasApple, sec);
    return sec;
}
