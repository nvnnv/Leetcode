void findsplitline(vector<vector<int>>& graph, int i, int j, int index)
{
    if (i < 0 || j < 0 || i >= graph.size() || j >= graph.size() || graph[i][j] == 1 || graph[i][j] != 0) return;
    graph[i][j] = index;
    findsplitline(graph, i - 1, j, index);
    findsplitline(graph, i, j-1, index);
    findsplitline(graph, i +1, j, index);
    findsplitline(graph, i, j+1, index);
}
int regionsBySlashes(vector<string>& grid) {
    if (grid.size()<=0) return 0;
    vector<vector<int>> fSlash = { {0,0,1},{0,1,0},{1,0,0} };
    vector<vector<int>> bSlash = { {1,0,0},{0,1,0},{0,0,1} };
    vector<vector<int>> blank = { {0,0,0},{0,0,0},{0,0,0} };
    vector<vector<int>> fm;
    for (auto& v : grid)
    {
        vector<int> l1;
        vector<int> l2;
        vector<int> l3;
        for (auto& c : v)
        {
            if (c == '\\')
            {
                l1.insert(l1.end(), bSlash[0].begin(), bSlash[0].end());
                l2.insert(l2.end(), bSlash[1].begin(), bSlash[1].end());
                l3.insert(l3.end(), bSlash[2].begin(), bSlash[2].end());
                continue;
            }
            if (c == '/')
            {
                l1.insert(l1.end(), fSlash[0].begin(), fSlash[0].end());
                l2.insert(l2.end(), fSlash[1].begin(), fSlash[1].end());
                l3.insert(l3.end(), fSlash[2].begin(), fSlash[2].end());
                continue;
            }
            l1.insert(l1.end(), blank[0].begin(), blank[0].end());
            l2.insert(l2.end(), blank[1].begin(), blank[1].end());
            l3.insert(l3.end(), blank[2].begin(), blank[2].end());
        }
        fm.push_back(l1);
        fm.push_back(l2);
        fm.push_back(l3);
    }
    int r = 2;
    unordered_set<int> s;
    for (int i = 0; i < fm.size(); ++i)
    {
        for (int j = 0; j < fm.size(); ++j)
        {
            if (fm[i][j] == 0)
            {
                findsplitline(fm, i, j, r);
                s.insert(r);
                ++r;
            }
        }
    }
    return s.size();
}
