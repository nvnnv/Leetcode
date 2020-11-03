void kill1(vector<vector<int>>& A, int x, int y)
{
    if (x < 0 || y < 0 || x >= A.size() || y >= A[x].size()) return;
    if (A[x][y] != 1) return;
    A[x][y] = 2;
    kill1(A, x, y+1);
    kill1(A, x, y-1);
    kill1(A, x+1, y);
    kill1(A, x-1, y);
}
int numEnclaves(vector<vector<int>>& A) {
    for (int i = 0; i < A.size(); ++i)
    {
        if(A[i][0] == 1) kill1(A, i, 0);
        if(A[i][A[i].size()-1] == 1) kill1(A, i, A[i].size() - 1);
    }
    for (int j = 0; j < A[0].size(); ++j)
    {
        if(A[0][j] == 1) kill1(A, 0, j);
        if(A[A.size()-1][j] == 1) kill1(A, A.size() - 1, j);
    }
    int num = 0;
    for (int i = 0; i < A.size(); ++i)
    {
        for (int j = 0; j < A[i].size(); ++j)
        {
            if (A[i][j] == 1) ++num;
        }
    }
    return num;
}
