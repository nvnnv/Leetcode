void markCity(int point, unordered_map<int, vector<int>>& road, set<int>& arrivable)
{
    arrivable.insert(point);
    if (!road.count(point)) return;
    for (auto v : road[point])
    {
        markCity(v, road, arrivable);
    }
}
void findRoad(int point, unordered_map<int, vector<int>>& road, set<int>& arrivable, int steps, int& _steps)
{
    if (!road.count(point)) return;
    for (int i=0;i<road[point].size(); ++i)
    {
        int v = road[point][i];
        if (arrivable.count(v))
        {
            _steps = steps;
            for (int j = i + 1; j < road[point].size(); ++j)
            {
                arrivable.insert(road[point][j]);
            }
            return;
        }
        findRoad(v, road, arrivable, steps + 1, _steps);
        if (_steps > 0)
        {
            arrivable.insert(v);
        }
    }
}
int minReorder(int n, vector<vector<int>>& connections) {
    unordered_map<int, vector<int>> road;
    for (auto& v : connections)
    {
        if (road.count(v[0]))
        {
            road[v[0]].push_back(v[1]);
        }
        else
        {
            vector<int> vv = { v[1] };
            road[v[0]] = vv;
        }
    }
    set<int> arrivable;
    int city = 0;
    markCity(city, road, arrivable);
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (arrivable.count(i)) continue;
        //0->i no road;
        int steps = -1;
        findRoad(i, road, arrivable, 1, steps);
        arrivable.insert(i);
        if(steps != -1) ans += steps;
    }
    return n - 1 - ans;
}
