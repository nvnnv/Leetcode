void findMinR(unordered_map<int, vector<pair<int, int>>>& g, int i, int r, int& minR)
{
    for (int j = 0; j < g[i].size(); ++j)
    {
        if (g[i][j].second > 0)
        {
            findMinR(g, g[i][j].first, r + g[i][j].second, minR);
        }
    }
    minR = max(r, minR);
}
int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    unordered_map<int, vector<pair<int, int>>> gg;
    for (int i = 0; i < manager.size(); ++i)
    {
        if (manager[i] != -1)
        {
            if (!gg.count(manager[i]))
            {
                vector<pair<int, int>> x;
                gg[manager[i]] = x;
            }
            gg[manager[i]].push_back({ i, informTime[manager[i]] });
        }
    }
    int a = 0;
    findMinR(gg, headID, 0, a);
    return a;
}
