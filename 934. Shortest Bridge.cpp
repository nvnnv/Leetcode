664ms
void reflag(vector<vector<int>>& A, int x, int y, int f, int ref, vector<vector<int>>& offset, int& h, int& w)
{
    if (A[x][y] != f) return;
    A[x][y] = ref;
    for (auto& i: offset)
    {
        int xx = x + i[0]; int yy = y + i[1];
        if (xx >= 0 && xx < h && yy >= 0 && yy < w) reflag(A, xx, yy, f, ref, offset, h, w);
    }
}
int shortestBridge(vector<vector<int>>& A) {
    vector<vector<int>> offset = { {0,1},{0,-1},{1,0},{-1,0} };
    int h = A.size();
    int w = A[0].size();

    int f = 0;
    vector<vector<int>> B;
    vector<vector<int>> C;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (!f && A[i][j]==1)
            {
                reflag(A, i, j, 1, 2, offset, h, w);
                f = 1;
            }
            if (A[i][j] == 2) B.push_back({ i,j });
            if (A[i][j] == 1) C.push_back({ i,j });
        }
    }
    int d = 1000000;
    for (auto& i : B)
        for (auto& j: C)
        {
            d = min(d, abs(i[0] - j[0]) + abs(i[1] - j[1]) - 1);
        }
    return d;
}
