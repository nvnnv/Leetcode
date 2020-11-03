void link1(vector<vector<int>>& g, int i, int j, int& x)
{
    if (i <0 || j< 0 || i>= g.size() || j>=g[i].size()) return;
    if (g[i][j]) return;
    g[i][j] = x;
    link1(g, i + 1, j, x);
    link1(g, i - 1, j, x);
    link1(g, i, j-1, x);
    link1(g, i, j+1, x);
}
int closedIsland(vector<vector<int>>& grid) {
    int odd = -1;
    int even = 0;
    for (int i = 0; i < grid.size(); ++i)
    {
        if (grid[i][0] == 0)
        {
                        odd += 2;
            link1(grid, i, 0, odd);
        }
        if (grid[i][grid[i].size() - 1] == 0)
        {
                        odd += 2;
            link1(grid, i, grid[i].size() - 1, odd);
        }
    }
    for (int j = 0; j < grid[0].size(); ++j)
    {
        if (grid[0][j] == 0)
        {
                        odd += 2;
            link1(grid, 0, j, odd);
        }
        if (grid[grid.size() - 1][j] == 0)
        {
                        odd += 2;
            link1(grid, grid.size() - 1, j, odd);
        }
    }
    for (int i = 1; i < grid.size(); ++i)
    {
        auto& v = grid[i];
        for (int j = 1; j < v.size(); ++j)
        {
            if (grid[i][j] == 0)
            {
                                   even += 2;
                   link1(grid, i, j, even);
            }
        }
    }
    return even/ 2;
}
