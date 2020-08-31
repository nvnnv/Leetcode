void bfsss(vector<vector<int>>& grid, int x, int y, int& step)
{
    ++step;
    grid[x][y] = 0;
    if (x > 0)
    {
        if (grid[x - 1][y] == 1) bfsss(grid, x - 1, y, step);  
    }
    if (y > 0)
    {
        if (grid[x][y - 1] == 1) bfsss(grid, x, y - 1, step);
    }
    if (x < grid.size()-1)
    {
        if (grid[x + 1][y] == 1) bfsss(grid, x + 1, y, step);
    }
    if (y < grid[0].size()-1)
    {
        if (grid[x][y + 1] == 1) bfsss(grid, x, y + 1, step);
    }
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int x = 0;
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[i].size(); ++j)
        {
            if (grid[i][j] == 1)
            {
                int step = 0;
                bfsss(grid, i, j, step);
                x = max(step, x);
            }
        }
    }
    return x;
}
