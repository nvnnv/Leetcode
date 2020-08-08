void ox(int point, int prev, unordered_map<int, vector<int>>& roads, vector<int>& passed, vector<int>& circle)
{
    passed.push_back(point);
    for (auto i : roads[point])
    {
        if (i == prev) continue;
        for (int j = 0; j < passed.size(); ++j)
        {
            if (passed[j] == i)
            {
                // circle
                for (int k = j; k < passed.size(); ++k)
                {
                    circle.push_back(passed[k]);
                }
                return;
            }
        }
        ox(i, point, roads, passed, circle);
        if (circle.size() > 0) return;
    }
    passed.pop_back();
}
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
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
            roads.insert(make_pair(v[0], vv));
        }
        if (roads.count(v[1]))
        {
            roads[v[1]].push_back(v[0]);
        }
        else
        {
            vector<int> vv = { v[0] };
            roads.insert(make_pair(v[1], vv));
        }
    }
    vector<int> pass;
    vector<int> circle;
    ox(1, -1, roads, pass, circle);
    vector<int> vv;
    for (int i = 0; i < edges.size(); ++i)
    {
        auto& v = edges[i];
        for (int j = 1; j < circle.size(); ++j)
        {
            if (circle[j] == v[0] && circle[j - 1] == v[1])
            {
                vv.push_back(i);
            }
            if (circle[j] == v[1] && circle[j - 1] == v[0])
            {
                vv.push_back(i);
            }
        }
        if (circle[0] == v[0] && circle[circle.size()-1] == v[1])
        {
            vv.push_back(i);
        }
        if (circle[0] == v[1] && circle[circle.size()-1] == v[0])
        {
            vv.push_back(i);
        }
    }
    sort(vv.begin(), vv.end());
    return edges[vv[vv.size()-1]];
}
