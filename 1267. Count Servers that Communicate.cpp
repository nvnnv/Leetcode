int countServers(vector<vector<int>>& grid) {
    int row = grid.size();
    int x = 0;
    for (int i = 0; i < row; ++i)
    {
        queue<pair<int,int>> q;
        int m = 0;
        for (int j = 0; j < grid[i].size(); ++j)
        {
            if (grid[i][j] == 1)
            {
                q.push(make_pair(i, j));
                ++m;
            }
        }
        if (m > 1)
        {
            while (!q.empty())
            {
                auto& p = q.front();
                q.pop();
                grid[p.first][p.second] = 2;
            }
            x += m;
        }
    }
    int col = grid[0].size();
    for (int j = 0; j < col; ++j)
    {
        int m = 0;
        int n = 0;
        for (int i = 0; i < row; ++i)
        {
            if (grid[i][j] > 0)
            {
                ++m;
                if (grid[i][j] == 2) ++n;
            }
        }
        if (m > 1)
        {
            x += m-n;
        }
    }
    return x;
}
